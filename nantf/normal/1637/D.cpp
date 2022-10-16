#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,a[maxn],b[maxn],s[maxn];
ll f[111][11111];
inline void chkmin(ll &x,ll y){x=min(x,y);}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) b[i]=read();
	FOR(i,1,n) s[i]=s[i-1]+a[i]+b[i];
	FOR(i,0,n) FOR(j,0,s[n]) f[i][j]=1e18;
	f[0][0]=0;
	FOR(i,0,n-1) FOR(j,0,s[i]) if(f[i][j]<1e18){
		int as=j,bs=s[i]-j;
		chkmin(f[i+1][j+a[i+1]],f[i][j]+1ll*as*a[i+1]+1ll*bs*b[i+1]);
		chkmin(f[i+1][j+b[i+1]],f[i][j]+1ll*as*b[i+1]+1ll*bs*a[i+1]);
	}
	ll ans=1e18;
	FOR(i,0,s[n]) ans=min(ans,f[n][i]);
	ans*=2;
	FOR(i,1,n) ans+=(n-1)*(a[i]*a[i]+b[i]*b[i]);
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--) solve();
}