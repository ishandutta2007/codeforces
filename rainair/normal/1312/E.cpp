#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 500+5;
int n,a[MAXN];
int dp[MAXN][MAXN],w[MAXN][MAXN];

inline int work(int l,int r){
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	if(l == r) {dp[l][r] = 1;w[l][r] = a[l];return 1;}
	int &res = dp[l][r];res = 1e9;w[l][r] = 0;
	FOR(mid,l,r-1){
		int gx = work(l,mid)+work(mid+1,r);
		if(gx < res){
			res = gx;w[l][r] = w[l][mid]+w[mid+1][r];
			if(dp[l][mid] == 1 && dp[mid+1][r] == 1 && w[l][mid]==w[mid+1][r]){
				res = 1;w[l][r] = w[l][mid]+1;
			}
		}
	}
	return res;
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	CLR(dp,-1);CLR(w,-1);
	printf("%d\n",work(1,n));
	return 0;
}