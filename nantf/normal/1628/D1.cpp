#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222,mod=1000000007,inv2=(mod+1)/2;
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
int n,m,k,f[maxn][maxn];
void solve(){
	n=read();m=read();
	n-=m;
	FOR(i,0,n) f[i][0]=0;
	FOR(i,0,m) f[0][i]=i;
	FOR(i,1,n) FOR(j,1,m) f[i][j]=(f[i-1][j]+f[i][j-1])*1ll*inv2%mod;
	printf("%lld\n",1ll*f[n][m]*read()%mod);
}
int main(){
	int T=read();
	while(T--) solve();
}