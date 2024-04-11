#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,q,block,tot,ncnt;
int v[300005],nxt[300005],h[150005],du[150005],siz[150005],dfn[150005],f[150005],sv[605][150005];
ll c[150005],ans[150005],cnt[150005];
vector<int> vec;

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; du[y]++;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot; du[x]++;
}

void add(int x,ll g){
	if(x>n) return;
	for(;x<=n;x+=(x&(-x))) c[x]=mod(c[x]+g);
}

ll ask(ll x){
	ll ret=0;
	for(;x;x-=(x&(-x))) ret=mod(ret+c[x]);
	return ret;
}

void dfs1(int u,int fa){
	siz[u]=1,dfn[u]=++ncnt;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]]=u;
		dfs1(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

void dfs2(int u,int fa,int r,int t,int s){
	if(u!=r) sv[t][u]=s;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(u==r){
			if(v[p]==f[u]) s=n-siz[u];
			else s=siz[v[p]];
			dfs2(v[p],u,r,t,s);
		}
		else dfs2(v[p],u,r,t,s);
	}
}

int main(){
	n=readint(); q=readint();
	block=350;
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs1(1,-1);
	for(int i=1;i<=n;i++) if(du[i]>=block) dfs2(i,-1,i,vec.size(),-1),vec.push_back(i);
	ll opt,x,y,invn=qpow(n,cys-2);
	for(int i=1;i<=q;i++){
		opt=readint(); x=readint();
		if(opt==1){
			y=readint();
			if(du[x]>=block) cnt[x]=mod(cnt[x]+y);
			else{
				ans[x]=mod(ans[x]+y);
				for(int p=h[x];p;p=nxt[p]){
					if(v[p]==f[x]){
						ll tmp=siz[x]*invn%cys*y%cys;
						add(1,tmp),add(dfn[x],cys-tmp),add(dfn[x]+siz[x],tmp);
					}
					else{
						ll tmp=(n-siz[v[p]])*invn%cys*y%cys;
						add(dfn[v[p]],tmp),add(dfn[v[p]]+siz[v[p]],cys-tmp);
					}
				}
			}
		}
		else{
			ll res=mod(ans[x]+ask(dfn[x]));
			for(int j=0;j<vec.size();j++){
				int r=vec[j];
				if(r==x) res=mod(res+cnt[r]);
				else res=(res+cnt[r]*(n-sv[j][x])%cys*invn)%cys;
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}