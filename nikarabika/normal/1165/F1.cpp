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

const int maxn = 2e5 + 100;
LL k[maxn],
   kk[maxn];
vector<int> poses[maxn],
	vec[maxn];
int n, m;

int get_last(vector<int> &v, int num) {
	int id = upper_bound(all(v), num) - v.begin();
	if (id == 0)
		return -1;
	return v[id - 1];
}

bool check(LL days) {
	for (int i = 0; i < maxn; i++)
		vec[i].clear();
	for (int i = 0; i < n; i++) {
		int pos = get_last(poses[i], days);
		if (~pos)
			vec[pos].PB(i);
	}
	LL money = 0;
	LL rem = 0;
	for (int i = 0; i < n; i++)
		rem += k[i];
	for (int i = 1; i < maxn and i <= days; i++) {
		money++;
		for (auto id : vec[i]) {
			LL val = min(k[id], money);
			rem -= val;
			money -= val;
		}
	}
	money += max(0LL, days - maxn + 1);
	return rem * 2 <= money;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> k[i];
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se, se--;
		poses[se].PB(fi);
	}
	for (int i = 0; i < n; i++)
		sort(all(poses[i]));
	LL lo = 0,
	   hi = 1e15;
	while (hi - lo > 1) {
		LL mid = (lo + hi) >> 1;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
	return 0;
}