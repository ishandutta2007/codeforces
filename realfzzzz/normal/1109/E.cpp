#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,m;
ll p,phi;
vector<ll> fac;
ll ksm(ll a,ll b){
	ll c=1;
	while(b){
		if(b%2==1) c=c*a%p;
		a=a*a%p;
		b/=2;
	}
	return c;
}
struct node{
	int l,r;
	node* ch[2];
	ll sum,mul=1;
	void pushup(){
		sum=(ch[0]->sum+ch[1]->sum)%p;
	}
	node(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushtag(ll k){
		sum=sum*k%p;
		mul=mul*k%p;
	}
	void pushdown(){
		ch[0]->pushtag(mul);
		ch[1]->pushtag(mul);
		mul=1;
	}
	void modify1(int ql,int qr,ll k){
		if(ql>r||qr<l) return;
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		ch[0]->modify1(ql,qr,k);
		ch[1]->modify1(ql,qr,k);
		pushup();
	}
	void modify2(int x,ll k){
		if(l==r){
			sum=k;
			return;
		}
		pushdown();
		if(x<=ch[0]->r) ch[0]->modify2(x,k);
		else ch[1]->modify2(x,k);
		pushup();
	}
	ll query(int ql,int qr){
		if(ql>r||qr<l) return 0;
		if(ql<=l&&qr>=r) return sum;
		pushdown();
		return (ch[0]->query(ql,qr)+ch[1]->query(ql,qr))%p;
	}
}*rt1,*rt2;
struct bit{
	int c[maxn];
	void modify(int x,int k){
		while(x<=n){
			c[x]+=k;
			x+=x&-x;
		}
	}
	int query(int x){
		int s=0;
		while(x){
			s+=c[x];
			x-=x&-x;
		}
		return s;
	}
}t[10];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	ll x=phi=p=read();
	for(int i=2;i*i<=x;i++) if(x%i==0){
		while(x%i==0) x/=i;
		phi=phi/i*(i-1);
		fac.push_back(i);
	}
	if(x>1){
		phi=phi/x*(x-1);
		fac.push_back(x);
	}
	rt1=new node(1,n);
	rt2=new node(1,n);
	for(int i=1;i<=n;i++){
		int a=read();
		rt1->modify2(i,a%p);
		for(int j=0;j<(int)fac.size();j++){
			int c=0;
			while(a%fac[j]==0){
				a/=fac[j];
				c++;
			}
			t[j].modify(i,c);
			t[j].modify(i+1,-c);
		}
		rt2->modify2(i,a%p);
	}
	m=read();
	while(m--){
		int opt=read();
		if(opt==1){
			int l,r,k;
			l=read();
			r=read();
			k=read();
			rt1->modify1(l,r,k%p);
			for(int i=0;i<(int)fac.size();i++){
				int c=0;
				while(k%fac[i]==0){
					k/=fac[i];
					c++;
				}
				t[i].modify(l,c);
				t[i].modify(r+1,-c);
			}
			rt2->modify1(l,r,k%p);
		}
		else if(opt==2){
			int x,k;
			x=read();
			k=read();
			ll s=rt2->query(x,x);
			for(int i=0;i<(int)fac.size();i++){
				int c=0;
				while(k%fac[i]==0){
					k/=fac[i];
					c++;
				}
				t[i].modify(x,-c);
				t[i].modify(x+1,c);
				s=s*ksm(fac[i]%p,t[i].query(x))%p;
			}
			rt1->modify2(x,s*ksm(k%p,phi-1)%p);
			rt2->modify1(x,x,ksm(k%p,phi-1));
		}
		else{
			int l,r;
			l=read();
			r=read();
			printf("%lld\n",rt1->query(l,r));
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}