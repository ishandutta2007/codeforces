#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444;
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
int n,mod,f[maxn][maxn][2],pw[maxn],ans,C[maxn][maxn];
inline int qmo(int x){return x+(x>>31?mod:0);}
int main(){
	n=read();mod=read();
	pw[0]=1;
	FOR(i,1,n) pw[i]=2*pw[i-1]%mod;
	FOR(i,0,n) C[i][0]=C[i][i]=1;
	FOR(i,1,n) FOR(j,1,i-1) C[i][j]=qmo(C[i-1][j]+C[i-1][j-1]-mod);
	f[0][0][0]=1;
	FOR(i,1,n) FOR(j,0,i){
		f[i][j][0]=f[i-1][j][1];
		FOR(k,1,j) f[i][j][1]=(f[i][j][1]+1ll*pw[k-1]*f[i-k][j-k][0]%mod*C[j][k])%mod;
	}
	FOR(i,0,n) ans=qmo(ans+f[n][i][1]-mod);
	printf("%d\n",ans);
}