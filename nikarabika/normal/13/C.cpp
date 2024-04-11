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

const int maxn = 5000;
LL dp[2][maxn],
   a[maxn];
vector<LL> all;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++){
		int cur = i & 1;
		int pre = !cur;
		for(int j = 0; j < sz(all); j++){
			dp[cur][j] = abs(a[i] - all[j]) + dp[pre][j];
			if(j) smin(dp[cur][j], dp[cur][j - 1]);
		}
	}
	cout << dp[(n - 1) & 1][sz(all) - 1] << endl;
	return 0;
}