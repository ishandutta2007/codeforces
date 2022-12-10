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

#define idof(x) (x == '?' ? 26 : x - 'a')

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	string s, t;
	cin >> n
		>> s
		>> t;
	vector<int> le[27], ri[27];
	for (int i = 0; i < n; i++)
		le[idof(s[i])].PB(i);
	for (int i = 0; i < n; i++)
		ri[idof(t[i])].PB(i);
	vector<pii> vec;
	for (int i = 0; i < 26; i++) {
		while (sz(le[i]) and sz(ri[i])) {
			vec.PB(MP(le[i].back(), ri[i].back()));
			le[i].pop_back();
			ri[i].pop_back();
		}
		while (sz(le[i]) and sz(ri[26])) {
			vec.PB(MP(le[i].back(), ri[26].back()));
			le[i].pop_back();
			ri[26].pop_back();
		}
		while (sz(le[26]) and sz(ri[i])) {
			vec.PB(MP(le[26].back(), ri[i].back()));
			le[26].pop_back();
			ri[i].pop_back();
		}
	}
	while (sz(le[26]) and sz(ri[26])) {
		vec.PB(MP(le[26].back(), ri[26].back()));
		le[26].pop_back();
		ri[26].pop_back();
	}
	cout << sz(vec) << '\n';
	for (auto boot : vec)
		cout << boot.L + 1 << ' ' << boot.R + 1 << '\n';
	return 0;
}