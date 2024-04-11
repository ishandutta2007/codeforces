#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=4444,mod=998244353,INF=1e9;
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
int n,m,a[maxn],s[maxn],c[maxn],f[maxn][maxn];
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) s[i]=read();
	FOR(i,1,n+m) c[i]=read();
	MEM(f,~0x3f);
	FOR(i,1,n+m) f[i][0]=0;
	ROF(i,n,1){
		ROF(j,n,1) f[a[i]][j]=max(f[a[i]][j],f[a[i]][j-1]+c[a[i]]-s[i]);
		int upr=n;
		FOR(j,a[i],n+m){
			FOR(k,0,upr) f[j+1][k/2]=max(f[j+1][k/2],f[j][k]+(k/2)*c[j+1]);
			upr>>=1;
		}
	}
	printf("%d\n",f[n+m][0]);
}