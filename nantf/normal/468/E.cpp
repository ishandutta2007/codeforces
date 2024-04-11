#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=66,maxm=111111,mod=1000000007;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int m,n,w[maxn][maxn],id1[maxm],c1,id2[maxm],c2,fac[maxm],ans;
ll e[maxn],ee[maxn];
unordered_map<ll,int> f[maxn][maxn];
inline void qmo(int &x){x+=(x>>31)&mod;}
int main(){
	m=read();n=read();
	while(n--){
		int u=read(),v=read(),w=(read()-1+mod)%mod;
		if(!w) continue; 
		if(!id1[u]) id1[u]=++c1;
		u=id1[u];
		if(!id2[v]) id2[v]=++c2;
		v=id2[v];
		::w[u][v]=w;
	}
	ROF(i,c2,1){
		ee[i]=ee[i+1];
		FOR(j,1,c1) if(w[j][i]) ee[i]|=1ll<<j;
	}
	f[0][0][0]=1;
	FOR(i,1,c2) FOR(j,0,i){
		for(auto k:f[i-1][j]) qmo(f[i][j][k.fi&ee[i]]+=k.se-mod);
		if(j) FOR(l,1,c1) if(w[l][i]) for(auto k:f[i-1][j-1]) if(!((k.fi>>l)&1))
			qmo(f[i][j][(k.fi|1ll<<l)&ee[i]]+=1ll*k.se*w[l][i]%mod-mod);
	}
	fac[0]=1;
	FOR(i,1,m) fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,0,min(c2,m)) for(auto j:f[c2][i]) ans=(ans+1ll*j.se*fac[m-i])%mod;
	printf("%d\n",ans);
}