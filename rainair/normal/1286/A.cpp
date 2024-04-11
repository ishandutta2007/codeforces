#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100+5;
int a[MAXN];
bool vis[MAXN];
int n;
int cnt[2];
int sm[MAXN];
int f[MAXN][MAXN][MAXN][2][2];
// [l,r] 0  x , 

inline int dp(int l,int r,int x,int a,int b){
	if(x < 0) return 1e9;
	int y = sm[r-1]-sm[l]-x;
	if(y < 0) return 1e9;
	if(f[l][r][x][a][b] != -1) return f[l][r][x][a][b];
	if(l == r) return (a==b) ? 0 : 1e9;
	if(l+1 == r) return (a!=b);
	int &res = f[l][r][x][a][b];res = 1e9;
	if(::a[l+1] == -1) res = std::min(res,std::min(dp(l+1,r,x-1,0,b)+(a!=0),dp(l+1,r,x,1,b)+(a!=1)));
	else res = std::min(res,dp(l+1,r,x,::a[l+1],b)+(a != ::a[l+1]));
	if(::a[r-1] == -1) res = std::min(res,std::min(dp(l,r-1,x-1,a,0)+(b!=0),dp(l,r-1,x,a,1)+(b!=1)));
	else res = std::min(res,dp(l,r-1,x,a,::a[r-1])+(b != ::a[r-1]));
	// printf("%d %d %d %d %d %d\n",l,r,x,a,b,res);
	return res;
}

int main(){
	// DEBUG(1);
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d",a+i);
		if(!a[i]) a[i] = -1;
		else a[i] %= 2,cnt[a[i]]++;
	}
	FOR(i,1,n) sm[i] = sm[i-1]+(a[i]==-1);
	cnt[0] = n/2-cnt[0];
	cnt[1] = (n+1)/2-cnt[1];
	CLR(f,-1);
	int ans = 1e9;
	FOR(i,0,1){
		if(a[1] != i && a[1] != -1) continue;
		FOR(j,0,1){
			if(a[n] != j && a[n] != -1) continue;
			int t1 = a[1],t2 = a[n];
			a[1] = i;a[n] = j;
			FOR(i,1,n) sm[i] = sm[i-1]+(a[i]==-1);
			ans = std::min(ans,dp(1,n,cnt[0]-((t1==-1&&i==0)+(t2==-1&&j==0)),i,j));
			a[1] = t1;a[n] = t2;
		}
	}
	printf("%d\n",ans);
	return 0;
}