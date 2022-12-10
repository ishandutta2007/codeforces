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

void solve() {
	string s;
	cin >> s;
	int a[26];
	memset(a, 0, sizeof a);
	for (auto c : s)
		a[c - 'a'] = 1;
	int first = -1,
		last = -1;
	int sum = 0;
	for (int i = 0; i < 26; i++) {
		sum += a[i];
		if (a[i]) {
			if (first == -1) first = i;
			last = i;
		}
	}
	if (sum == sz(s) and last - first + 1 == sum)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}