#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define gcd __gcd

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=505;
const int maxm=2e5+5;

int n,m,mod;
char str[maxn][maxn];
ll dp[2][maxn][maxn];

void add(ll &a,ll b){(a+=b)%=mod;}

ll fast_mod(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1)res=res*x%mod;
		x=x*x%mod,k>>=1;
	}
	return res;
}

ll C[maxn][maxn];

void pre(){
	C[0][0]=1;
	for(int i=1;i<maxn;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=m;i++)scanf("%s",str[i]+1);
	pre();
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++)if(str[j][i]=='1')cnt++;
		if(cnt==0)cnt0++;
		if(cnt==1)cnt1++;
	}
	//bug(cnt0),debug(cnt1);
	dp[0][cnt0][cnt1]=1;
	int cur=0;
	for(int i=m+1;i<=n;i++){
		for(int c0=0;c0<=n;c0++)for(int c1=0;c1<=n;c1++)if(dp[cur][c0][c1]){
			//printf("dp[%d][%d][%d]=%lld\n",cur,c0,c1,dp[cur][c0][c1]);
			//00
			if(c0>=2)add(dp[1-cur][c0-2][c1+2],dp[cur][c0][c1]*C[c0][2]%mod);
			//01
			if(c1>=1&&c0>=1)add(dp[1-cur][c0-1][c1],dp[cur][c0][c1]*c0%mod*c1%mod);
			//11
			if(c1>=2)add(dp[1-cur][c0][c1-2],dp[cur][c0][c1]*C[c1][2]%mod);
		}
		cur=1-cur;
	}
	printf("%lld\n",dp[cur][0][0]);
	return 0;
}