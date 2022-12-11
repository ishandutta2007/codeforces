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

const int maxn = 3000 + 85 - 69;
LL dp[2][maxn],
   a[maxn];
int n;
vector<LL> all;

LL Abs(LL x){
	return x < 0 ? -x : x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] -= i;
		all.PB(a[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	memset(dp, 63, sizeof dp);
	for(int j = 0; j < sz(all); j++){
		dp[0][j] = Abs(all[j] - a[0]);
		if(j) smin(dp[0][j], dp[0][j - 1]);
	}
	for(int i = 1; i < n; i++){
		int cur = i&1,
			pre = i&1^1;
		memset(dp[cur], 63, sizeof dp[cur]);
		int cval = lower_bound(all(all), a[i]) - all.begin();
		for(int j = 0; j < sz(all); j++){
			dp[cur][j] = Abs(a[i] - all[j]) + dp[pre][j];
			if(j) smin(dp[cur][j], dp[cur][j - 1]);
		}
	}
	cout << dp[(n - 1)&1][sz(all) - 1] << '\n';
	return 0;
}