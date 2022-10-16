#include <bits/stdc++.h>
using namespace std;

struct johnwick_tree{
	int n;
	vector<long long> tree;
 
	johnwick_tree(int n) {
		this->n = n;
		tree.resize(n+1);
	}
 
	void update(int p, long long val){
		for (int i = p; i <= n; i += i & -i) {
			tree[i] += val;
		}
	}
 
	long long sum(int p) {
		if (p == 0) return 0;
		long long ans = 0;
		for (int i = p; i; i -= i & -i) {
			ans += tree[i];
		}
		return ans;
	}
};

#define int long long

vector<int> solve1(vector<int> a, int n) {
	vector<int> pos(n+1);
	for (int i = 0; i < n; i++) {
		pos[a[i]] = i+1;
	}

	vector<int> ans(n+1);
	set<int> l, r;
	int lsum = 0, rsum = 0;

	for (int i = 1; i <= n; i++) {
		r.insert(pos[i]); rsum += pos[i];

		while (l.size() && r.size()) {
			auto itl = l.end(); itl--;
			auto itr = r.begin();
			if (*itl > *itr) {
				lsum -= *itl; rsum += *itl;
				lsum += *itr; rsum -= *itr;

				l.insert(*itr); r.insert(*itl);
				l.erase(itl); r.erase(itr);
			} else {
				break;
			}
		}
		

		while (l.size() < r.size()) {
			auto it = r.begin();
			lsum += *it; rsum -= *it;
			l.insert(*it);
			r.erase(it);
		}
		auto it = l.end(); it--;

		int mid = *it;
		int ls = l.size(), rs = r.size();
		int ansl = mid*ls - ls*(ls-1)/2 - lsum;
		int ansr = rsum - ((mid+1)*rs + rs*(rs-1)/2);

		ans[i] = ansl + ansr;
	}
	return ans;
}

vector<int> solve2(vector<int> a, int n) {
	vector<int> pos(n+1);
	for (int i = 0; i < n; i++) {
		pos[a[i]] = i+1;
	}

	vector<int> ans(n+1);
	int anscur = 0;
	johnwick_tree tr(n);
	for (int i = 1; i <= n; i++) {
		anscur += i - tr.sum(pos[i]) - 1;
		tr.update(pos[i], 1);
		ans[i] = anscur;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> v1 = solve1(a, n);
	vector<int> v2 = solve2(a, n);

	for (int i = 1; i <= n; i++) {
		cout << v1[i] + v2[i] << '\n';
	}

	return 0;
}