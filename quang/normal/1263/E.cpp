#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;

struct IT {
	struct Node {
		int minPref, maxPref;
		int sum;
		Node(int minPref = 0, int maxPref = 0, int sum = 0) : 
			minPref(minPref), maxPref(maxPref), sum(sum) {}
	} t[N << 2];

	void pull(int node) {
		t[node].sum = t[node << 1].sum + t[node << 1 | 1].sum;
		t[node].minPref = min(t[node << 1].minPref, t[node << 1].sum + t[node << 1 | 1].minPref);
		t[node].maxPref = max(t[node << 1].maxPref, t[node << 1].sum + t[node << 1 | 1].maxPref);
	}

	void update(int node, int l, int r, int id, int val) {
		if (id > r || id < l) return;
		if (l == r) {
			t[node] = Node(min(0, val), max(0, val), val);
			return;
		}
		int m = l + r >> 1;
		update(node << 1, l, m, id, val);
		update(node << 1 | 1, m + 1, r, id, val);
		pull(node);
	}

	bool isGood() {
		return t[1].sum == 0 && t[1].minPref >= 0;
	}
} t;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	string s; cin >> s;
	int curPos = 1;
	int n = s.size();
	for (char u : s) {
		if (u == 'L') curPos = max(curPos - 1, 1);
		else if (u == 'R') curPos++;
		else {
			if (u == '(') t.update(1, 1, n, curPos, 1);
			else if (u == ')') t.update(1, 1, n, curPos, -1);
			else t.update(1, 1, n, curPos, 0);
		}
		if (t.isGood()) {
			cout << t.t[1].maxPref << ' ';
		} else cout << -1 << ' ';
	}
	cout << endl;
	return 0;
}