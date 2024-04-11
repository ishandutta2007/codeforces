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

const int maxn = 5e5 + 10;
int fen[maxn];
int mark[maxn];
int x[maxn],
	y[maxn],
	ord[maxn],
	n;
vector<int> all;

void inc(int idx) {
	for (idx++; idx < maxn; idx += idx & -idx)
		fen[idx]++;
}

int get(int idx) {
	int ans = 0;
	for (; idx; idx -= idx & -idx)
		ans += fen[idx];
	return ans;
}

int get(int st, int en) {
	return get(en) - get(st);
}

bool cmp(int i, int j) {
	return y[i] != y[j] ? y[i] > y[j] : x[i] < x[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		all.PB(x[i]);
		all.PB(y[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for (int i = 0; i < n; i++) {
		x[i] = lower_bound(all(all), x[i]) - all.begin();
		y[i] = lower_bound(all(all), y[i]) - all.begin();
	}
	
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		int id = ord[i];
		if (!mark[x[id]]) {
			mark[x[id]] = true;
			inc(x[id]);
		}
		int lcnt = 1 + get(0, x[id]);
		int rcnt;
		if (i + 1 < n and y[ord[i + 1]] == y[id])
			rcnt = 1 + get(x[id] + 1, x[ord[i + 1]]);
		else
			rcnt = 1 + get(x[id] + 1, sz(all));
		ans += 1LL * lcnt * rcnt;
	}
	cout << ans << endl;
	return 0;
}