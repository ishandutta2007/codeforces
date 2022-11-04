#pragma GCC optimize("O3")
#pragma GCC target("sse3,sse4,avx")

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <memory.h>
#include <iomanip>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 2e18 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()

template<typename A, typename B> bool mini(A &x, const B &y) {
	if (y < x) {
		x = y;
		return 1;
	}
	return 0;
}
#define mp make_pair
void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	run();
#ifdef _DEBUG
	cerr << "OK" << endl;
	while (1);
#endif
	return 0;
}

const int N = (int) 1e5 + 123;

int n, m;
int w[N];
pair<int, int> a[N];
int best[N];
int b[N], p[N];
vector<int> have[N];

void run() {
	cin >> n >> m;
	rep(i, 0, n) {
		cin >> a[i].first;
		a[i].second = i;
		w[i] = a[i].first;
	}
	sort(a, a + n);
	best[n] = -1;
	per(i, n - 1, 0) {
		best[i] = max(best[i + 1], a[i].second);
	}
	rep(i, 0, m) {
		cin >> b[i];
	}
	rep(i, 0, m) {
		cin >> p[i];
	}
	int ans = 0;
	rep(i, 0, m) {
		int need = b[i];
		int ind = (int)(lower_bound(a, a + n, mp(need, -1)) - a);
		if (ind < n) {
			have[best[ind]].push_back(i);
		}
	}
	ll money = 0;
	multiset<int> q;
	rep(i, 0, n) {
		money += w[i];
		for (int id : have[i]) {
			int need = p[id];
			if (money >= need) {
				money -= need;
				q.insert(need);
				ans++;
			}
			else if (sz(q)) {
				int worst = *q.rbegin();
				if (worst > need) {
					q.erase(q.find(worst));
					q.insert(need);
					money += worst;
					money -= need;
				}
			}
		}
	}
	cout << ans << "\n";
}