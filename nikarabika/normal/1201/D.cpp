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

const int maxn = 2e5 + 20;
vector<LL> vec[maxn],
	cols;
LL dpl[maxn],
   dpr[maxn];
int n, m, k, q;

LL Abs(LL x) {
	return (x < 0) ? -x : x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		vec[fi].PB(se);
	}
	for (int i = 0; i < n; i++)
		sort(all(vec[i]));
	if (vec[0].empty())
		vec[0].push_back(0);

	for (int i = 0; i < q; i++) {
		int c;
		cin >> c;
		cols.PB(c - 1);
	}
	sort(all(cols));

	memset(dpl, 63, sizeof dpl);
	memset(dpr, 63, sizeof dpr);
	dpl[0] = vec[0].back() * 2 - vec[0].front();
	dpr[0] = vec[0].back();
	int prv = 0;
	LL ans = min(dpl[0], dpr[0]);
	//cout << "#" << 0 << ' ' << dpl[0] << ' ' << dpr[0] << endl;
	for (int i = 1; i < n; i++) if (sz(vec[i])) {
		for (auto pos : vec[i]) {
			int id = lower_bound(all(cols), pos) - cols.begin();
			if (id != sz(cols)) {
				LL c = cols[id];
				LL cost = (i - prv) + min(dpl[prv] + Abs(vec[prv].front() - c), dpr[prv] + Abs(vec[prv].back() - c));
				//cout << "CF: " << cost << endl;
				smin(dpl[i], cost + max(0LL, vec[i].back() - c) + max(c, vec[i].back()) - vec[i].front());
				smin(dpr[i], cost + max(0LL, c - vec[i].front()) + vec[i].back() - min(c, vec[i].front()));
			}
			if (id - 1 >= 0) {
				LL c = cols[id - 1];
				LL cost = (i - prv) + min(dpl[prv] + Abs(vec[prv].front() - c), dpr[prv] + Abs(vec[prv].back() - c));
				//cout << "CB: " << cost << endl;
				//cout << i - prv << ' ' << dpl[prv] << ' ' << Abs(vec[prv].front() - c) << ' ' << dpr[prv] << ' ' << Abs(vec[prv].back() - c) << endl;
				smin(dpl[i], cost + max(0LL, vec[i].back() - c) + max(c, vec[i].back()) - vec[i].front());
				smin(dpr[i], cost + max(0LL, c - vec[i].front()) + vec[i].back() - min(c, vec[i].front()));
			}
		}
		ans = min(dpl[i], dpr[i]);
		//cout << "#" << i << ' ' << dpl[i] << ' ' << dpr[i] << endl;
		prv = i;
	}
	cout << ans << endl;
	return 0;
}