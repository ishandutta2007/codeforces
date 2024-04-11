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
vector<pii> opn[maxn];
vector<int> clz[maxn];
int n, k;
set<pii> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--;
		opn[fi].PB(MP(-se, i));
		clz[se].PB(i);
	}
	vector<int> ans;
	for (int i = 0; i < maxn; i++) {
		for (auto seg : opn[i])
			s.insert(seg);
		for (auto seg : clz[i])
			s.erase(MP(-i, seg));
		while (sz(s) > k) {
			ans.PB(s.begin()->R);
			s.erase(s.begin());
		}
	}
	cout << sz(ans) << '\n';
	for (auto seg : ans)
		cout << seg + 1 << ' ';
	cout << '\n';
	return 0;
}