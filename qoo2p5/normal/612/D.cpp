#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n, k;
vector<pair<int, int>> events;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		events.pb(mp(l, 0));
		events.pb(mp(r, 1));
	}

	sort(events.begin(), events.end());
	int cnt = 0;
	bool opened = false;
	int border;
	vector<pair<int, int>> segments;

	for (int i = 0; i < sz(events); i++) {
		int j = i;
		while (j + 1 < sz(events) && events[j + 1].first == events[j].first) {
			j++;
		}

		int ncnt = cnt;

		for (int k = i; k <= j; k++) {
			if (!events[k].second) {
				cnt++;
				ncnt++;
			} else {
				cnt--;
			}
		}

		if (ncnt >= k) {
			if (!opened) {
				opened = true;
				border = events[i].first;
			}
		}

		if (cnt < k) {
			if (opened) {
				opened = false;
				segments.pb(mp(border, events[i].first));
			}
		}

		i = j;
	}


	vector<pair<int, int>> ans;

	for (int i = 0; i < sz(segments); i++) {
		int j = i;
		while (j + 1 < sz(segments) && segments[j + 1].first == segments[j].second) {
			j++;
		}

		ans.pb(mp(segments[i].first, segments[j].second));
		i = j;
	}

	cout << sz(ans) << "\n";
	for (auto &s : ans) {
		cout << s.first << " " << s.second << "\n";
	}

    return 0;
}