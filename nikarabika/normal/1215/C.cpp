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

int n;
string s, t;
vector<int> vec[2][2];
vector<pii> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n
		>> s
		>> t;
	for (int i = 0; i < n; i++)
		s[i] -= 'a';
	for (int i = 0; i < n; i++)
		t[i] -= 'a';
	for (int i = 0; i < n; i++)
		vec[s[i]][t[i]].PB(i + 1);
	if ((sz(vec[0][1]) + sz(vec[1][0])) & 1)
		return cout << -1 << endl, 0;
	while (sz(vec[0][1]) > 1) {
		auto &pos = vec[0][1];
		int p = pos.back();
		pos.pop_back();
		int q = pos.back();
		pos.pop_back();
		ans.PB(MP(p, q));
	}
	while (sz(vec[1][0]) > 1) {
		auto &pos = vec[1][0];
		int p = pos.back();
		pos.pop_back();
		int q = pos.back();
		pos.pop_back();
		ans.PB(MP(p, q));
	}
	if (sz(vec[1][0])) {
		int p = vec[1][0][0];
		int q = vec[0][1][0];
		ans.PB(MP(p, p));
		ans.PB(MP(p, q));
	}
	cout << sz(ans) << endl;
	for (auto sw : ans)
		cout << sw.L << ' ' << sw.R << '\n';
	return 0;
}