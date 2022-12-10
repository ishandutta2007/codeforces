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

const int maxn = 2e5 + 10;
bool cnt[2][maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (cnt[0][x]) {
			if (cnt[1][x])
				return cout << "NO\n", 0;
			else
				cnt[1][x] = 1;
		}
		else
			cnt[0][x] = 1;
	}
	cout << "YES\n";
	vector<int> vec;
	for (int i = 0; i < maxn; i++)
		if (cnt[0][i])
			vec.PB(i);
	cout << sz(vec) << '\n';
	for (auto val : vec)
		cout << val << ' ';
	cout << '\n';

	vec.clear();
	for (int i = maxn - 1; i >= 0; i--)
		if (cnt[1][i])
			vec.PB(i);
	cout << sz(vec) << '\n';
	for (auto val : vec)
		cout << val << ' ';
	cout << '\n';
	return 0;
}