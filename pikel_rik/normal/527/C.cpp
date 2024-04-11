#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int w, h, n;
	cin >> w >> h >> n;

	set<int> sw = {0, w}, sh = {0, h};
	multiset<int> diffw = {w}, diffh = {h};

	while (n--) {
        char c;
        cin >> c;

        if (c == 'H') {
            int y;
            cin >> y;
            auto it = sh.lower_bound(y);
            auto prv = prev(it);
            sh.insert(y);
            diffh.erase(diffh.find(*it - *prv));
            diffh.insert(*it - y);
            diffh.insert(y - *prv);
        } else if (c == 'V') {
            int x;
            cin >> x;
            auto it = sw.lower_bound(x);
            auto prv = prev(it);
            sw.insert(x);
            diffw.erase(diffw.find(*it - *prv));
            diffw.insert(*it - x);
            diffw.insert(x - *prv);
        }

        cout << (long long)*diffh.rbegin() * *diffw.rbegin() << '\n';
	}
	return 0;
}