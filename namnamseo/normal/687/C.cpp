#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int dp[510][510];
int n,k;
int c[510];

bool seen[510][510][510];
set<int> anses;

void dfs(int p,int q,int r){
	if(seen[p][q][r]) return;
	seen[p][q][r] = true;
	anses.insert(q);

	if(p == 0) return;

	if(dp[p][r] & 1){
		dfs(p-1, q, r);
	}
	if(dp[p][r] & 2){
		dfs(p-1, q     , r-c[p]);
		dfs(p-1, q-c[p], r-c[p]);
	}
}

int main(){
	read(n,k);
	for(int i=1; i<=n; ++i) read(c[i]);
	sort(c+1, c+n+1);

	dp[0][0] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=0; j<=k; ++j){
			if(dp[i-1][j]) dp[i][j] |= 1;
			if(j >= c[i] && dp[i-1][j-c[i]]) dp[i][j] |= 2;
		}
	}
	dfs(n, k, k);

	printf("%d\n", sz(anses));
	for(int t : anses) printf("%d ",t);

	return 0;
}