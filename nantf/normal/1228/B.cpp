#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111,mod=1000000007;
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
int n,m,ans=1,mat[maxn][maxn];
int main(){
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,m) mat[i][j]=-1;
	FOR(i,1,n){
		int x=read();
		FOR(j,1,x){
			if(mat[i][j]==0) return puts("0"),0;
			mat[i][j]=1;
		}
		if(x!=m){
			if(mat[i][x+1]==1) return puts("0"),0;
			mat[i][x+1]=0;
		}
	}
	FOR(j,1,m){
		int x=read();
		FOR(i,1,x){
			if(mat[i][j]==0) return puts("0"),0;
			mat[i][j]=1;
		}
		if(x!=n){
			if(mat[x+1][j]==1) return puts("0"),0;
			mat[x+1][j]=0;
		}
	}
//	FOR(i,1,n){
//		FOR(j,1,m) printf("%d ",mat[i][j]);
//		puts("");
//	}
	FOR(i,1,n) FOR(j,1,m) if(mat[i][j]==-1) ans=2ll*ans%mod;
	printf("%d\n",ans);
}