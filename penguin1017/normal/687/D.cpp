#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
#define pos(x,y) (x+y|(x!=y))
using namespace std;
const ll mod=998244353;
const ll Inf=1e18;
/*
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int sub(int a,const int &b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
int jie[N],inv[N];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
*/
const int N=1009;
const int M=N*(N-1);
int u[M>>1],v[M>>1],w[M>>1],fa[M],col[M];
vector<int> g[M];
bool ok;
int find(int x){
	if(fa[x]==x)return x;
	int rt=fa[x];
	fa[x]=find(fa[x]);
	col[x]^=col[rt];
	return fa[x];
}
void upd(int x){fa[x]=x;col[x]=0;} 
vi merge(const vi &a,const vi &b){
	vi res;
	res.clear();
	for(auto x:a)upd(u[x]),upd(v[x]);
	for(auto x:b)upd(u[x]),upd(v[x]);
	for(int i=0,j=0,x;i<a.size()||j<b.size();){
		if(j==b.size()||(i<a.size()&&w[a[i]]>=w[b[j]]))x=a[i++];
		else x=b[j++];
		int fu=find(u[x]),fv=find(v[x]);
		if(fu!=fv){
			col[fu]=col[u[x]]^col[v[x]]^1;fa[fu]=fv;
			res.pb(x);
		}
		else if(col[u[x]]==col[v[x]]){
			res.pb(x);
			ok=1;
			break;
		}
	}
	return res;
}
void build(int l,int r){
	if(l==r){
		g[pos(l,r)].pb(l);
		return ;
	}
	int m=l+r>>1;
	build(l,m);build(m+1,r);
	g[pos(l,r)]=merge(g[pos(l,m)],g[pos(m+1,r)]);
}
vi get(int L,int R,int l,int r){
	if(L<=l&&r<=R)return g[pos(l,r)];
	int m=l+r>>1;
	vi a,b;
	if(L<=m)a=get(L,R,l,m);
	if(R>m)b=get(L,R,m+1,r);
	return merge(a,b);
}
int main(){
	//pre();
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,m+1)scanf("%d%d%d",&u[i],&v[i],&w[i]);
	build(1,m);
	vi em;
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		ok=0;
		vi s=get(l,r,1,m);
		merge(s,em);
		if(ok)printf("%d\n",w[s[s.size()-1]]);
		else puts("-1");
	}
}
/*
5 6 1
5 4 86
5 1 0
1 3 38
2 1 33
2 4 28
2 3 40

1 6
*/