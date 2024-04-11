#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

typedef long long ll;

int n, p;
deque<pair<int,int>> t;
ll r[101010];
deque<int> ad;
set<int> as;
set<int> bs;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		t.push_back({x,i});
	}
	sort(t.begin(),t.end());
	ll g = 0;
	int c = 0;
	int f = 0;
	while (c < n) {
		while (t.size() && t[0].first <= g) {
			if ((f == 0 || f > t[0].second) && (bs.size() == 0 || *bs.begin() > t[0].second) && (as.size() == 0 || *as.begin() > t[0].second)) {
				ad.push_back(t[0].second);
				as.insert(t[0].second);
			} else {
				bs.insert(t[0].second);
			}
			t.pop_front();
		}
		if (bs.size() && (as.size() == 0 || *as.begin() > *bs.begin())) {
			ad.push_back(*bs.begin());
			as.insert(*bs.begin());
			bs.erase(*bs.begin());
		}
		if (ad.size()) {
			c++;
			g += p;
			r[ad[0]] = g;
			f = ad[0];
			as.erase(ad[0]);
			ad.pop_front();
		} else if (t.size()) {
			g = t[0].first;
			f = 0;
		}
	}
	for (int i = 1; i <= n; i++) cout << r[i] << " ";
	cout << "\n";
}