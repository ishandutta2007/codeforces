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

const int MAXN = 5000+5;
char str[MAXN][MAXN];int n;
std::vector<int> G[26];
int vis[26];
// bool ok[MAXN];

int main(){
	scanf("%s",str[0]+1);n = strlen(str[0]+1);
	FOR(i,1,n-1){
		int t = 0;
		FOR(j,i+1,n) str[i][++t] = str[0][j];
		FOR(j,1,i) str[i][++t] = str[0][j];
	}
	FOR(i,0,n-1) G[str[i][1]-'a'].pb(i);
	int ans = 0;
	FOR(i,0,25){
		int gx = 0;
		FOR(ps,2,n){
			CLR(vis,0);int t = 0;
			for(auto x:G[i]) vis[str[x][ps]-'a']++;
			FOR(k,0,25) t += (vis[k]==1);
			gx = std::max(gx,t);
		}
		ans += gx;
	}
	printf("%.10f\n",1.0*ans/n);
	return 0;
}