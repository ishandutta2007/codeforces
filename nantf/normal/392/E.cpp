#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444,mod=998244353,INF=1e9;
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
int n,w[maxn],a[maxn],l[maxn][maxn],d[maxn][maxn],f[maxn][maxn],dp[maxn];
int main(){
	n=read();
	FOR(i,1,n) w[i]=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) f[i][i]=w[1];
	ROF(i,n,1) FOR(j,i+1,n){
		l[i][j]=d[i][j]=f[i][j]=-INF;
		FOR(k,i,j-1) if(a[k]+1==a[j]) l[i][j]=max(l[i][j],l[i][k]+f[k+1][j-1]);
		FOR(k,i,j-1) if(a[k]-1==a[j]) d[i][j]=max(d[i][j],d[i][k]+f[k+1][j-1]);
		FOR(k,i,j-1) f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
		if(a[j]>=a[i] && a[j]-a[i]+1<=n) f[i][j]=max(f[i][j],l[i][j]+w[a[j]-a[i]+1]);
		if(a[j]<=a[i] && a[i]-a[j]+1<=n) f[i][j]=max(f[i][j],d[i][j]+w[a[i]-a[j]+1]);
		FOR(k,i+1,j-1) if(a[k]>=a[i] && a[k]>=a[j] && 2*a[k]-a[i]-a[j]+1<=n)
			f[i][j]=max(f[i][j],l[i][k]+d[k][j]+w[2*a[k]-a[i]-a[j]+1]);
	}
	FOR(i,1,n){
		dp[i]=dp[i-1];
		FOR(j,0,i-1) dp[i]=max(dp[i],dp[j]+f[j+1][i]);
	}
	printf("%d\n",dp[n]);
}