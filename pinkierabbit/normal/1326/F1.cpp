#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 14
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,a[MN][MN];
std::vector<int>G[1<<14];
int f[1<<14][14][1<<6],g[1<<14][14][1<<6];
void solve(int m){
	F2(i,0,n)f[1<<i][i][0]=1;
	F2(S,1,1<<n){
		int c=__builtin_popcount(S);
		if(c==1||c>m)continue;
		for(int i:G[S]){
			int T=S^1<<i;
			for(int j:G[T]){
				//f[T][j][?]->f[S][i][?] (a[j][i])
				if(a[j][i]){
					F2(X,0,1<<(c-1))
						f[S][i][X<<1|1]+=f[T][j][X];
				}else{
					F2(X,0,1<<(c-1))
						f[S][i][X<<1]+=f[T][j][X];
				}
			}
		}
	}
}
int rev[1<<6];
ll ans[1<<13];
int main(){
	scanf("%d",&n);
	F2(i,0,n)F2(j,0,n)scanf("%1d",&a[i][j]);
	F2(S,0,1<<n)F2(i,0,n)if(S>>i&1)G[S].push_back(i);
	int c=n/2-1;
	F2(S,1,1<<c)rev[S]=(rev[S>>1]>>1)|((S&1)<<(c-1));
//	F2(S,0,1<<c)printf("rev[%d]=%d\n",S,rev[S]);
	solve(n/2);
	memcpy(g,f,sizeof f);
	memset(f,0,sizeof f);
	solve(n-n/2);
	F2(S,1,1<<n){
		int c=__builtin_popcount(S);
		if(c!=n-n/2)continue;
		
//		for(int i:G[S])F2(X,0,1<<(n-n/2-1))if(f[S][i][X])printf("f[%d][%d][%d]=%d\n",S,i,X,f[S][i][X]);
		
		int T=((1<<n)-1)^S;
		for(int i:G[S])
			for(int j:G[T]){
				int z=a[i][j];
				F2(X,0,1<<(n-n/2-1))if(f[S][i][X]){
					int Z=(X<<1|z)<<(n/2-1);
					F2(Y,0,1<<(n/2-1))if(g[T][j][Y]){
						ans[Z|rev[Y]]+=(ll)f[S][i][X]*g[T][j][Y];
//						printf("  f[%d][%d][%d]=%d\n",S,i,X,f[S][i][X]);
//						printf("  g[%d][%d][%d]=%d\n",T,j,Y,g[T][j][Y]);
//						printf("\t\t\t\tans[%d]+=%lld\n",Z|rev[Y],(ll)f[S][i][X]*g[T][j][Y]);
					}
				}
			}
	}
	F2(i,0,1<<(n-1))printf("%lld ",ans[i]);
	return 0;
}