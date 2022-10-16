#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=255,mod=998244353;
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
int n,p[maxn],q[maxn],tmp[maxn],to[maxn*2],deg[maxn*2],cnt[2][2],tot,f[maxn][maxn],fac[maxn*2],inv[maxn*2],invfac[maxn*2],S[maxn][maxn],a[maxn],b[maxn],c[maxn],ans[maxn];
bool vis[maxn*2];
inline int C(int n,int m){
	if(n<m || n<0 || m<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main(){
	n=read();
	FOR(i,1,n) p[i]=read();
	FOR(i,1,n) if(q[i]=read()) tmp[q[i]]=i;
	FOR(i,1,n) q[i]=tmp[i];
	FOR(i,1,n) if(p[i]) to[i]=p[i]+n,deg[to[i]]++;
	FOR(i,1,n) if(q[i]) to[i+n]=q[i],deg[to[i+n]]++;
	FOR(i,1,2*n) if(!deg[i]){
		int u=i;
		while(to[u]) vis[u]=true,u=to[u];
		vis[u]=true;
		cnt[i>n][u>n]++;
	}
	FOR(i,1,2*n) if(!vis[i]){
		tot++;
		int u=i;
		while(!vis[u]) vis[u]=true,u=to[u];
	}
	assert(cnt[0][0]==cnt[1][1]);
	fac[0]=fac[1]=inv[1]=invfac[0]=invfac[1]=1;
	FOR(i,2,2*n){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		invfac[i]=1ll*invfac[i-1]*inv[i]%mod;
	}
	S[0][0]=1;
	FOR(i,1,n) FOR(j,1,i) S[i][j]=(S[i-1][j-1]+1ll*(i-1)*S[i-1][j])%mod;
	int upr=cnt[0][0];
	FOR(i,0,upr) a[i]=1ll*fac[upr]*S[upr][i]%mod;
	upr=cnt[0][1];
	FOR(i,0,upr) FOR(j,0,i){
		if(cnt[0][0]) b[j]=(b[j]+1ll*C(upr,i)*fac[upr-i]%mod*C(upr-i+cnt[0][0]-1,upr-i)%mod*S[i][j])%mod;
		else if(i==upr) b[j]=(b[j]+1ll*C(upr,i)*fac[upr-i]%mod*S[i][j])%mod;
	}
	upr=cnt[1][0];
	FOR(i,0,upr) FOR(j,0,i){
		if(cnt[0][0]) c[j]=(c[j]+1ll*C(upr,i)*fac[upr-i]%mod*C(upr-i+cnt[0][0]-1,upr-i)%mod*S[i][j])%mod;
		else if(i==upr) c[j]=(c[j]+1ll*C(upr,i)*fac[upr-i]%mod*S[i][j])%mod;
	}
	FOR(i,0,n) FOR(j,0,n-i) FOR(k,0,n-i-j) ans[i+j+k]=(ans[i+j+k]+1ll*a[i]*b[j]%mod*c[k])%mod;
	FOR(i,0,n-1) printf("%d ",n-i-tot>=0?ans[n-i-tot]:0);
}