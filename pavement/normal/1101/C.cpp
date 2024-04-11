#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mt make_tuple
 
int T, N, L[200005], R[200005], A[200005];
vector<tuple<int, bool, int> > seg;
stack<int> cur;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int dis = 0, segn = 0;
		cin >> N;
		seg.clear();
		while (!cur.empty()) cur.pop();
		for (int i = 1; i <= N; i++) {
			cin >> L[i] >> R[i];
			seg.push_back(mt(L[i], 0, i));
			seg.push_back(mt(R[i], 1, i));
		}
		sort(seg.begin(), seg.end());
		for (int i = 0, c = 0, st = 0; i < seg.size(); i++) {
			if (c == 0 && !get<1>(seg[i])) st = get<0>(seg[i]);
			c += (get<1>(seg[i]) ? -1 : 1);
			if (c == 0) {
				dis++;
				while (!cur.empty()) {
					A[cur.top()] = segn, cur.pop();
				}
				segn++;
			}
			if (!get<1>(seg[i])) cur.push(get<2>(seg[i]));
		}
		if (dis == 1) cout << "-1\n";
		else {
			for (int i = 1; i <= N; i++)
				if (A[i] & 1) cout << "1 ";
				else cout << "2 ";
			cout << '\n';
		}
	}
}