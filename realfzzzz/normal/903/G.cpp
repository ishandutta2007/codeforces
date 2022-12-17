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
const int maxn=2e5+5;
int n,m,q,a[maxn],b[maxn];
vector<pair<int,int>> g[maxn];
struct node{
	int l,r;
	node* ch[2];
	ll mn,add=0;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			mn=b[r];
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void pushtag(ll k){
		mn+=k;
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,ll k){
		if(ql>r||qr<l) return;
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		ch[0]->modify(ql,qr,k);
		ch[1]->modify(ql,qr,k);
		pushup();
	}
}*rt;
ll c[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	q=read();
	for(int i=1;i<n;i++){
		a[i]=read();
		b[i]=read();
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();
		v=read();
		w=read();
		g[u].push_back({v,w});
	}
	rt=new node(0,n-1);
	multiset<ll> s;
	for(int i=1;i<=n;i++){
		for(auto e:g[i])
			rt->modify(0,e.first-1,e.second);
		s.insert((c[i]=rt->mn)+a[i]);
	}
	printf("%lld\n",*s.begin());
	while(q--){
		int x=read();
		s.erase(s.find(c[x]+a[x]));
		s.insert(c[x]+(a[x]=read()));
		printf("%lld\n",*s.begin());
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}