#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111,mod=1000000007;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,K,f[maxn][maxn*maxn],C[maxn][maxn],a[4][maxn][maxn][256];
ll m;
inline int lpow(int i,int j,int b){
	return 1ll*a[0][i][j][b&255]*a[1][i][j][(b>>8)&255]%mod*a[2][i][j][(b>>16)&255]%mod*a[3][i][j][b>>24]%mod;
}
int main(){
	n=read();m=read();K=read();
	FOR(i,0,n) C[i][0]=C[i][i]=1;
	FOR(i,1,n) FOR(j,1,i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	FOR(i,0,n) FOR(j,0,i){
		a[0][i][j][0]=1;
		a[0][i][j][1]=C[i][j];
		FOR(k,0,3){
			FOR(l,2,255) a[k][i][j][l]=1ll*a[k][i][j][l-1]*a[k][i][j][1]%mod;
			if(k!=3){
				a[k+1][i][j][0]=1;
				a[k+1][i][j][1]=1ll*a[k][i][j][255]*a[k][i][j][1]%mod;
			}
		}
	}
	f[0][0]=1;
	FOR(i,1,n) FOR(j,0,K) FOR(k,0,min(j,n)){
		int pw=(m/n+(m%n>=i))%(mod-1);
		f[i][j]=(f[i][j]+1ll*f[i-1][j-k]*lpow(n,k,pw))%mod;
	}
	printf("%d\n",f[n][K]);
}