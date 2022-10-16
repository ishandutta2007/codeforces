#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,a[maxn],b[maxn],c[maxn],bs,f[2][maxn][maxn*maxn*2],g[2][maxn][maxn*maxn*2],cur,ans[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read(),b[i]=read();
	FOR(i,1,n) bs+=b[i],c[i]=2*a[i]-b[i];
	MEM(f,~0x3f);MEM(g,~0x3f);
	cur=0;
	f[0][0][0]=0;
	FOR(i,1,n){
		cur^=1;
		FOR(j,0,i) FOR(k,0,200*i){
			f[cur][j][k]=f[cur^1][j][k];
			if(j && k>=c[i]) f[cur][j][k]=max(f[cur][j][k],f[cur^1][j-1][k-c[i]]+2*a[i]);
		}
	}
	FOR(i,1,n) FOR(j,0,bs) ans[i]=max(ans[i],f[cur][i][j]); 
	cur=0;
	g[0][0][0]=0;
	FOR(i,1,n){
		cur^=1;
		FOR(j,0,i) FOR(k,0,200*i){
			g[cur][j][k]=g[cur^1][j][k];
			if(j && k>=c[i]) g[cur][j][k]=max(g[cur][j][k],g[cur^1][j-1][k-c[i]]+b[i]);
		}
	}
	FOR(i,1,n) FOR(j,bs,200*n) ans[i]=max(ans[i],g[cur][i][j]+bs); 
	FOR(i,1,n) printf("%.6lf ",1.0*ans[i]/2);
}