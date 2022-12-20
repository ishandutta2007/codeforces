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
int n,m,a[maxn];
struct node{
	int l,r;
	node* ch[2];
	ll mn,ass,add;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
	}
	node(int l,int r):l(l),r(r),add(0){
		if(l==r){
			ll x=1;
			while(x<a[r]) x*=42;
			mn=x-a[r];
			ass=a[r];
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
		ass=-1;
	}
	void pushass(ll k){
		ll x=1;
		while(x<k) x*=42;
		mn=x-k;
		ass=k;
		add=0;
	}
	void pushadd(ll k){
		mn-=k;
		if(ass>=0) ass+=k;
		else add+=k;
	}
	void pushdown(){
		if(ass>=0){
			ch[0]->pushass(ass);
			ch[1]->pushass(ass);
			ass=-1;
		}
		ch[0]->pushadd(add);
		ch[1]->pushadd(add);
		add=0;
	}
	void modify1(int ql,int qr,ll k){
		if(ql>r||qr<l) return;
		if(ql<=l&&qr>=r){
			pushass(k);
			return;
		}
		pushdown();
		ch[0]->modify1(ql,qr,k);
		ch[1]->modify1(ql,qr,k);
		pushup();
	}
	ll modify2(int ql,int qr,ll k){
		if(ql>r||qr<l) return 9e18;
		if(ql<=l&&qr>=r){
			if(ass>=0){
				pushass(ass+k);
				return mn;
			}
			if(mn>=k){
				pushadd(k);
				return mn;
			}
		}
		pushdown();
		ll res=min(ch[0]->modify2(ql,qr,k),ch[1]->modify2(ql,qr,k));
		pushup();
		return res;
	}
	ll query(int x){
		if(ass>=0) return ass;
		pushdown();
		if(x<=ch[0]->r) return ch[0]->query(x);
		else return ch[1]->query(x);
	}
}*rt;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	rt=new node(1,n);
	while(m--){
		int opt=read();
		if(opt==1) printf("%lld\n",rt->query(read()));
		else if(opt==2){
			int l,r,x;
			l=read();
			r=read();
			x=read();
			rt->modify1(l,r,x);
		}
		else{
			int l,r,x;
			l=read();
			r=read();
			x=read();
			while(rt->modify2(l,r,x)==0);
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}