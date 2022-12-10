//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 85 - 69,
	  maxk = 300 + 1;
int dp[maxk][maxn],
	a[maxn],
	b[maxn];
vector<int> vec[maxn];
int n, m, s, e;
int ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> e;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i], vec[b[i]].PB(i);
	memset(dp, 63, sizeof dp);
	fill(dp[0], dp[0] + maxn, -1);
	for(int j = 0; j < n; j++){
		int ptr = 0;
		for(int i = 1; i <= 300 and i <= j + 1; i++){
			if(j){
				dp[i][j] = dp[i][j - 1];
				while(ptr < sz(vec[a[j]]) and vec[a[j]][ptr] <= dp[i - 1][j - 1]) ptr++;
				if(ptr < sz(vec[a[j]])) smin(dp[i][j], vec[a[j]][ptr]);
			}
			else{
				while(ptr < sz(vec[a[j]]) and vec[a[j]][ptr] <= -1) ptr++;
				if(ptr < sz(vec[a[j]])) smin(dp[i][j], vec[a[j]][ptr]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= 300; i++)
		for(int j = 0; j < n; j++)
			if(j + dp[i][j] + 1 + 1 <= s - e * i)
				smax(ans, i);
	cout << ans << endl;
	return 0;
}