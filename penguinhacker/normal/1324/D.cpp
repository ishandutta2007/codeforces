#include <bits/stdc++.h>
using namespace std;

#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define data tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

int n, a[200000], b[200000];
data p;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll ans = 0;
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	for (int i=0, c; i<n; ++i) {
		c = a[i]-b[i];
		ans += p.order_of_key(c);
		p.insert(-c);
	}
	cout << ans;
	return 0;
}