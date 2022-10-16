#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
      using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long

struct johnwick_tree{
	int n;
	vector<long long> tree;

	johnwick_tree(int n) {
		this->n = n;
		tree.resize(n+3);
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
} tr(250000);

int sq(int n) {
	return n*(n + 1)/2;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> s(n+1), a(n+1);
    for (int i = 1; i <= n; i++) {
		cin >> s[i];
    }
    indexed_set<int> sk;
	for (int i = 1; i <= n; i++) {
		tr.update(i, i);
		sk.insert(i);
	}

	for (int i = n; i; i--) {
        int lo = 1, hi = i;
        while (lo < hi) {
			int mid = (lo + hi)/2;

            int actual_val = *sk.find_by_order(mid - 1);
            if (tr.sum(actual_val - 1) == s[i]) {
				lo = mid; break;
            } else if (tr.sum(actual_val - 1) < s[i]) {
				lo = mid + 1;
            } else {
				hi = mid - 1;
            }
        }
		int ss = *sk.find_by_order(lo - 1);
        sk.erase(sk.find_by_order(lo - 1));
        tr.update(ss, -ss);

        a[i] = ss;
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}

    return 0;
}