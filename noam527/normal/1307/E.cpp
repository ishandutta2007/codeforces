#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m;
vector<int> s, cnt;
vector<vector<int>> pos;
vector<vector<pair<int, int>>> a;

pair<int, int> calc(vector<int> &h, int s) {
	if (h.size() == 0) return{ 0, 1 };
	sort(h.begin(), h.end());
	if (h[0] > s) return{ 0, 1 };
	if (h.size() == 1) return{ 1, 2 };
	if (h[0] + h[1] > s) {
		int cnt = 0;
		for (const auto &i : h)
			if (i <= s) cnt++;
		return{ 1, 2 * cnt };
	}
	int total = 0;
	int nxt = (int)h.size() - 1;
	for (int i = 0; i < h.size(); i++) {
		while (nxt >= 0 && h[i] + h[nxt] > s) nxt--;
		total += nxt + 1;
	}
	for (const auto &i : h)
		if (i + i <= s) total--;
	return{ 2, total };
}

pair<int, int> calc1(const vector<pair<int, int>> &h, int lim) {
	if (h.size() == 0) return{ 0, 1 };
	if (h[0].first > lim && h[0].second < lim) return{ 0, 1 };
	if (h.size() == 1) {
		//cout << "here: " << h[0].first << " " << h[0].second << '\n';
		int sum = 0;
		if (h[0].first < lim) sum++;
		if (h[0].second > lim) sum++;
		return{ 1, sum };
	}

	// size >= 2
	if ((h[0].first > lim || h[1].second < lim) && (h[0].second < lim || h[1].first > lim)) {
		int sum = 0;
		for (const auto &i : h) {
			if (i.first < lim) sum++;
			if (i.second > lim) sum++;
		}
		return{ 1, sum };
	}

	int p1 = 0, p2 = 0;
	while (p1 < h.size() && h[p1].first < lim) p1++;
	while (p2 < h.size() && h[p2].second > lim) p2++;
	return{ 2, p1 * p2 - min(p1, p2) };
}

pair<int, int> calc2(const vector<pair<int, int>> &h, int lim) {
	if (h.size() <= 1) return{ 0, 1 };
	if (h[0].second <= lim) return{ 0, 1 };
	if (h[0].first == lim && h[1].second <= lim) return{ 0, 1 };
	int sum = 0;
	for (const auto &i : h) {
		if (i.second > lim && i.first != lim)
			sum++;
	}
	return{ 1, sum };
}

pair<int, int> work(int lim) {
	//cout << "work " << lim << '\n';
	int type = -1;
	for (int i = 0; i < n; i++) {
		for (const auto &j : a[i])
			if (j.first == lim)
				type = i;
	}
	if (type == -1) return{ -1, -1 };

	//cout << "type " << type << '\n';

	int ans = 0, sum = 1;
	for (int i = 0; i < n; i++) {
		pair<int, int> res;
		if (i != type)
			res = calc1(a[i], lim);
		else
			res = calc2(a[i], lim);
		ans += res.first;
		sum = ((ll)sum * res.second) % md;
	}
	//cout << "is: " << ans << " " << sum << '\n';
	return{ ans + 1, sum };
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	s.resize(n);
	cnt.resize(n, 0);
	pos.resize(n);
	for (auto &i : s) {
		cin >> i;
		--i;
		cnt[i]++;
	}
	for (int i = 0; i < n; i++)
		pos[s[i]].push_back(i);
	a.resize(n);
	for (int i = 0, f, h; i < m; i++) {
		cin >> f >> h;
		--f;
		if (h <= cnt[f]) {
			a[f].emplace_back(pos[f][h - 1], pos[f][(int)pos[f].size() - h]);
		}
	}
	for (int i = 0; i < n; i++)
		sort(a[i].begin(), a[i].end());

	pair<int, int> best = { 0, 1 };
	for (int i = 0; i < n; i++) {
		pair<int, int> res = work(i);
		if (res.first > best.first) best = res;
		else if (res.first == best.first) {
			best.second = (best.second + res.second) % md;
		}
	}
	if (best.first == 0) {
		cout << "0 1\n";
		return 0;
	}
	// only right
	int ans = 0, sum = 1;
	for (int i = 0; i < n; i++) {
		if (a[i].size()) {
			ans++;
			sum = ((ll)sum * (ll)a[i].size()) % md;
		}
	}
	if (ans > best.first) {
		best = { ans, sum };
	}
	else if (ans == best.first) {
		best.second = (best.second + sum) % md;
	}
	cout << best.first << " " << best.second << '\n';
}