#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=33,mod=998244353;
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
inline int qmo(int x){return x+(x>>31)*mod;}
int n,q,ans[111111][2],al;
ll a[maxn][maxn],b[maxn][maxn];
void work(int x,int y,ll res){
	ans[++al][0]=x;
	ans[al][1]=y;
	if(x==n && y==n) return;
	if(x==n) return work(x,y+1,res);
	if(y==n) return work(x+1,y,res);
	res-=a[x][y];
//	printf("(%d,%d),sum=%lld\n",x,y,sum);
	if(res<=b[x][y+1]) work(x,y+1,res);
	else work(x+1,y,res);
}
int main(){
	n=read();
	FOR(i,2,n) a[i][n-1]=1;
	ROF(j,n-2,1) FOR(i,2,n){
		ll sum=1;
		FOR(k,i-1,n) sum+=a[k][j+1];
		FOR(k,j+2,n) sum+=a[n][k];
		FOR(k,j+1,n) sum-=a[i][k];
		FOR(k,i+1,n) sum-=a[k][n]; 
		a[i][j]=sum;
	}
	ROF(i,n,1) b[n][i]=b[n][i+1]+a[n][i];
	ROF(i,n-1,1) FOR(j,1,n) b[i][j]=b[i+1][j]+a[i][j];
	FOR(i,1,n){
		FOR(j,1,n) printf("%lld ",a[i][j]);
		puts("");
	}
	fflush(stdout);
	q=read();
	while(q--){
		ll x=read();
		al=0;
		work(1,1,x);
		FOR(i,1,al) printf("%d %d\n",ans[i][0],ans[i][1]);
		fflush(stdout);
	}
}