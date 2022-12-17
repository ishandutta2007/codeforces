#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=100+5,maxm=1e5+5;
int n,m,q;
ll a[maxn],b[maxm];
struct node{
	int l,r;
	node* ch[2];
	ll mx,sum,add=0;
	void pushup(){
		mx=ch[1]->mx;
		sum=ch[0]->sum+ch[1]->sum;
	}
	node(int l,int r):l(l),r(r),mx(b[r]-b[r-1]),sum(b[r]-b[l-1]){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushtag(ll k){
		mx+=k;
		sum+=k*(r-l+1);
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,ll k){
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
		pushup();
	}
	ll query1(int ql,int qr){
		if(ql<=l&&qr>=r) return sum;
		pushdown();
		ll ans=0;
		if(ql<=ch[0]->r) ans+=ch[0]->query1(ql,qr);
		if(qr>=ch[1]->l) ans+=ch[1]->query1(ql,qr);
		return ans;
	}
	int query2(ll x){
		if(l==r) return mx>x?r:r+1;
		pushdown();
		if(ch[0]->mx>x) return ch[0]->query2(x);
		else return ch[1]->query2(x);
	}
}*rt;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	rt=new node(2,m);
	ll s=0;
	for(int i=1;i<=m;i++) s+=b[i];
	while(q--){
		int type,k;
		type=readint();
		k=readint();
		ll d=readint();
		if(type==1) for(int i=1;i<=k;i++) a[n-k+i]+=d*i;
		else{
			if(k==m){
				b[1]+=d;
				rt->pushtag(d);
			}
			else rt->modify(m-k+1,m,d);
			s+=d*k*(k+1)/2;
		}
		ll ans=s;
		int lst=1;
		for(int i=1;i<n;i++){
			int x=rt->query2(a[i+1]-a[i])-1;
			ans+=a[i]*(x-lst+1)+b[1]+(x>1?rt->query1(2,x):0);
			lst=x;
		}
		printf("%lld\n",ans+a[n]*(m-lst+1));
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}