#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<iostream>
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

template<class T>inline void rd(T &x){
    x=0;char c;
    while(c=getchar(),c<48);
    do x=(x<<3)+(x<<1)+(c^48);
    while(c=getchar(),c>47);
}

const int maxn=4000+50;
const int maxm=800+50;

int n,m;
int A[maxn][maxn],sum[maxn][maxn];
int dp[maxm][maxn];

void solve(int l,int r,int opt_l,int opt_r,int kth){
	if(l>r||opt_l>opt_r)return;
	
	int mid=(l+r)>>1,opt_pos=opt_l;
	for(int i=opt_l;i<=min(r-1,opt_r);i++){
		if(dp[kth-1][i]+sum[i+1][mid]<dp[kth][mid])
			opt_pos=i,dp[kth][mid]=dp[kth-1][i]+sum[i+1][mid];
	}
	
	solve(l,mid-1,opt_l,opt_pos,kth);
	solve(mid+1,r,opt_pos,opt_r,kth);
}

int main(){
	rd(n),rd(m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)rd(A[i][j]),A[i][j]+=A[i][j-1];
	
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)sum[i][j]=sum[i][j-1]+A[j][j]-A[j][i-1];
	
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)dp[1][i]=sum[1][i];
	
	for(int i=2;i<=m;i++)solve(1,n,1,n,i);
	
	printf("%d\n",dp[m][n]);
	return 0;
}