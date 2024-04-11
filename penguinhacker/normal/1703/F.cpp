#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		Tree<int> s;
		ll ans=0;
		for (int i=1; i<=n; ++i) {
			int a;
			cin >> a;
			if (a<i) {
				ans+=s.order_of_key(a);
				s.insert(i);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}