#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=3666,mod=998244353;
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
int n,m,k,totr,totc,C[maxn][maxn],f[maxn],g[maxn],ans,fac[maxn];
bool vr[maxn],vc[maxn];
int main(){
	n=read();m=read();k=2*read();
	while(k--) vr[read()]=true,vc[read()]=true;
	FOR(i,0,max(n,m)) C[i][i]=C[i][0]=1;
	FOR(i,1,max(n,m)) FOR(j,1,i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	fac[0]=1;
	FOR(i,1,max(n,m)) fac[i]=1ll*fac[i-1]*i%mod;
	f[0]=1;
	FOR(i,1,n){
		if(vr[i]) continue;
		int j=i;
		while(j<=n && !vr[j]) j++;
		j--;
		int len=j-i+1;
		ROF(i,n/2,0) FOR(k,1,min(i,len/2)) f[i]=(f[i]+1ll*C[len-k][k]*f[i-k])%mod;
		i=j;
		totr+=len;
	}
	g[0]=1;
	FOR(i,1,m){
		if(vc[i]) continue;
		int j=i;
		while(j<=m && !vc[j]) j++;
		j--;
		int len=j-i+1;
		ROF(i,m/2,0) FOR(k,1,min(i,len/2)) g[i]=(g[i]+1ll*C[len-k][k]*g[i-k])%mod;
		i=j;
		totc+=len;
	}
	FOR(i,0,totr/2) FOR(j,0,totc/2) ans=(ans+1ll*f[i]*g[j]%mod*C[totr-2*i][j]%mod*C[totc-2*j][i]%mod*fac[i]%mod*fac[j])%mod;
//	FOR(i,0,n/2) printf("f[%d]=%d\n",i,f[i]);
//	FOR(i,0,m/2) printf("g[%d]=%d\n",i,g[i]);
//	FOR(i,0,n/2) assert(f[i]==C[n-i][i]);
//	FOR(i,0,m/2) assert(g[i]==C[m-i][i]);
	printf("%d\n",ans);
}