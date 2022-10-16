#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e17;

void process1(vector<int> &a, vector<pair<int, int>> &seg) {
	// remove already visited segments

	vector<pair<int, int>> nxt;
	for (auto [l, r]: seg) {
		int pos = lower_bound(a.begin(), a.end(), l) - a.begin();
		if (pos != a.size() && a[pos] <= r) {
			continue;
		} else {
			nxt.emplace_back(l, r);
		}
	}
	swap(seg, nxt);
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

void process2(vector<pair<int, int>> &seg) {
	// if there are nesting segments, remove the outer
	sort(seg.begin(), seg.end(), cmp);

	vector<pair<int, int>> nxt;
	int lm = INF, rm = INF;
	for (auto [l, r]: seg) {
		if (l == lm) continue;
		if (r >= rm) continue;
		rm = r, lm = l;
		nxt.emplace_back(l, r);
	}
	swap(seg, nxt);

	sort(seg.begin(), seg.end());
}

vector<vector<pair<int, int>>> split_seg(vector<int> a, vector<pair<int, int>> seg) {
	vector<vector<pair<int, int>>> ans;
	int petr = 0;
	for (int i = 1; i < a.size(); i++) {
		vector<pair<int, int>> spl;

		while (petr < seg.size() && seg[petr].second < a[i]) {
			spl.push_back(seg[petr]); petr++;
		}

		ans.push_back(spl);
	}
	return ans;
}

vector<int> make_transition(int l, int r, vector<pair<int, int>> seg, vector<pair<int, int>> prv, vector<int> dp) {
	vector<int> nxt(seg.size() + 1, INF);

	// special case: seg is empty
	if (seg.empty()) {
		nxt[0] = *min_element(dp.begin(), dp.end());
		return nxt;
	}

	// special case: prv is empty
	if (prv.empty()) {
		nxt = vector<int>(seg.size() + 1, dp[0]);
		int n = seg.size();

		// all covered by r
		nxt[n] += abs(r - seg[0].second);
		// all covered by l
		nxt[0] += abs(l - seg[n-1].first);
		for (int i = 0; i+1 < n; i++) {
			nxt[n-i-1] += abs(l - seg[i].first) + abs(r - seg[i+1].second);
		}
		return nxt;
	}

	// both non-empty
	int n = seg.size();
	vector<int> pref = dp, suf = dp;
	for (int i = 1, j = prv.size() - 1; i < dp.size(); i++, j--) {
		pref[i] += abs(l - prv[j].second);
		pref[i] = min(pref[i], pref[i-1]);
	}
	for (int i = dp.size() - 2; i >= 0; i--) {
		suf[i] = min(suf[i], suf[i+1]);
	}

	// dp
	// all covered by r
	nxt[n] = (*min_element(dp.begin(), dp.end())) + abs(r - seg[0].second);

	// at least one covered by non-r
	for (int i = 0, j = n-1, petr = prv.size() - 1, cnt = 0; i < n; i++, j--) {
		// up to i covered by l, i+1 onwards covered by r
		int lenl = 0, lenr = 0;
		lenl = abs(l - seg[i].first);
		if (i+1 < n) lenr = abs(r - seg[i+1].second);

		while (petr >= 0 && abs(l - prv[petr].second) <= lenl) {
			petr--; cnt++;
		}

		if (cnt+1 < suf.size()) nxt[j] = min(nxt[j], lenr + lenl*2 + suf[cnt+1]);
		if (cnt >= 0) nxt[j] = min(nxt[j], lenr + lenl + pref[cnt]);
	}

	return nxt;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a.push_back(-INF);
	a.push_back(INF);
	sort(a.begin(), a.end());

	vector<pair<int, int>> seg;
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		seg.emplace_back(l, r);
	}

	process1(a, seg);
	process2(seg);
	vector<vector<pair<int, int>>> segs = split_seg(a, seg);

	vector<int> dp(segs[0].size() + 1, INF);
	// dp[i]: min cost such that, in the previous segment
	// exactly i segments were covered by their right endpoint
	if (!segs[0].empty()) {
		dp[segs[0].size()] = abs(a[1] - segs[0][0].second);
	} else {
		dp[0] = 0;
	}

	/*for (auto pp: segs) {
		cout << "Segments:\n";
		for (auto [u, v]: pp) {
			cout << u << ' ' << v << '\n';
		}
	}*/

	/*cout << "DP:\n";
	for (int j: dp) cout << j << ' ';
		cout << '\n';*/

	for (int i = 1; i < segs.size(); i++) {
		dp = make_transition(a[i], a[i+1], segs[i], segs[i-1], dp);
		/*cout << "DP:\n";
		for (int j: dp) cout << j << ' ';
			cout << '\n';*/
	}

	//cout << "Final answer: ";
	cout << *min_element(dp.begin(), dp.end()) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}