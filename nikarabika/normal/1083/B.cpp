//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL n, k;
	string s, t;
	cin >> n >> k
		>> s
		>> t;
	LL ans = 0;
	LL dis = -1;
	for (int i = 0; i < n; i++) {
		dis = min((LL)1e15, dis * 2 + 'b' - s[i] + t[i] - 'a');
		ans += min(k, dis + 2);
	}
	cout << ans << endl;
	return 0;
}