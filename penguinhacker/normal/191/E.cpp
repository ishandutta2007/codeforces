#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

int n, a[100000];
ll k;

bool ok(ll x) {
	Tree<ar<ll, 2>> t;
	t.insert({0, -1});
	ll sum=0, cnt=0;
	for (int i=0; i<n; ++i) {
		sum+=a[i];
		cnt+=t.order_of_key({sum-x, (ll)1e9});
		t.insert({sum, i});
	}
	return cnt>=k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) cin >> a[i];
	ll l=-1e14, r=1e14;
	while(l<r) {
		ll mid=(l+r+1)/2;
		if (ok(mid)) l=mid;
		else r=mid-1;
	}
	cout << l;
	return 0;
}