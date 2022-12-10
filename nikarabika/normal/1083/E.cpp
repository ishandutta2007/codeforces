//sobskdrbhvk
//remember... ):(
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
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 1e6 + 10;
vector<int> stc;
LL x[maxn],
   y[maxn],
   a[maxn],
   dp[maxn];
int ord[maxn];
int n;

LD tagh(int i, int j) {
	return LD(dp[i] - dp[j]) / LD(x[i] - x[j]);
}

void add(int id) {
	while (sz(stc) >= 2 and tagh(id, stc.back()) >= tagh(stc.back(), stc[sz(stc) - 2]))
		stc.pop_back();
	stc.PB(id);
}

int get(LD pos) {
	int lo = 0,
		hi = sz(stc);
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (tagh(stc[mid], stc[mid - 1]) >= pos)
			lo = mid;
		else
			hi = mid;
	}
	return stc[lo];
}

bool xcmp(int i, int j) {
	return x[i] < x[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	stc.reserve(1e6 + 10);
	cin >> n;
	n++;
	for (int i = 1; i < n; i++)
		cin >> x[i] >> y[i] >> a[i];
	iota(ord, ord + n, 0);
	sort(ord, ord + n, xcmp);
	
	add(0);
	for (int i = 1; i < n; i++) {
		int id = ord[i];
		int bid = get(y[id]);
		dp[id] = dp[bid] + (x[id] - x[bid]) * y[id] - a[id];
		add(id);
		/*cout << bid << ' ' << x[id] << ' '<< dp[id] << endl;
		for (auto idd : stc)
			cout << "#" << idd;
		cout << endl;
		*/
	}
	cout << *max_element(dp, dp + n) << endl;

	return 0;
}