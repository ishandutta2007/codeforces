#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

int n, m, a[1000000];
Tree<ar<int, 2>> t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		if (x==-1) {
			auto it=upper_bound(a, a+m, t.size());
			int ind=it-a-1;
			for (int j=ind; ~j; --j) {
				t.erase(t.find_by_order(a[j]-1));
			}
		} else {
			t.insert({i, x});
		}
	}
	if (t.empty()) {
		cout << "Poor stack!";
	} else {
		for (const auto& x : t)
			cout << x[1];
	}
	return 0;
}