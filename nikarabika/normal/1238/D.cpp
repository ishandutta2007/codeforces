//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s >> s;
	int cnt = 1;
	vector<int> vec;
	s += 'C';
	for (int i = 1; i < sz(s); i++) {
		if (s[i] != s[i - 1])
			vec.PB(cnt), cnt = 0;
		cnt++;
	}
	LL ans = 1LL * sz(s) * (sz(s) - 1) / 2;
	for (int i = 1; i < sz(vec); i++)
		ans -= vec[i] + vec[i - 1] - 1;
	ans -= sz(s) - 1;
	cout << ans << endl;
	return 0;
}