#include <bits/stdc++.h>
using namespace std;

int sign(int i, int j, int k) {
	// gets orientation for i->j and j->k
	cout << "2 " << j << ' ' << i << ' ' << k << endl;
	int sgn; cin >> sgn;
	return sgn;
}

long long area(int i, int j, int k) {
	cout << "1 " << i << ' ' << j << ' ' << k << endl;
	long long are; cin >> are;
	return are;
}

vector<int> solve(int a, int b, vector<int> c) {
	if (c.empty()) return vector<int>(0);
	// suppose answer permutation is of the form (a, b, arranged c)
	// first, find the point with the maximum area

	vector<pair<long long, int>> f;
	for (int i: c) {
		f.emplace_back(area(a, b, i), i);
	}
	sort(f.begin(), f.end());

	// suppose a, b is on the x-axis, the pivot is definitely the highest point
	int pt = f.back().second;

	vector<pair<long long, int>> left, right;
	// answer: a->b->right sorted->pivot->left reverse sorted
	for (auto [x, i]: f) {
		if (i == pt) continue;
		if (sign(a, pt, i) == -1) {
			// ccw, left
			left.emplace_back(x, i);
		} else {
			// cw, right
			right.emplace_back(x, i);
		}
	}
	sort(right.begin(), right.end());
	sort(left.begin(), left.end());
	reverse(left.begin(), left.end());

	vector<int> ans;
	for (auto [x, i]: right) {
		ans.push_back(i);
	}
	ans.push_back(pt);
	for (auto [x, i]: left) {
		ans.push_back(i);
	}

	return ans;
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	// first, partition into 2 parts: above (1, 2) and below(1, 2)
	vector<int> ccw, cw;
	for (int i = 3; i <= n; i++) {
		int c = sign(1, 2, i);
		if (c == -1) {
			ccw.push_back(i);
		} else {
			cw.push_back(i);
		}
	}

	// now solve each separately
	// answer has the form (1, 2, solve(ccw)) and (1, solve)
	vector<int> ct = solve(2, 1, cw);
	vector<int> cct = solve(1, 2, ccw);

	cout << "0 1 ";
	for (int i: ct) cout << i << ' ';
	cout << "2 ";
	for (int i: cct) cout << i << ' ';
		cout << endl;

	return 0;
}