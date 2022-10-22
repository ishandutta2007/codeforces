#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=200000;
int n, a[mxN], b[mxN];
ll ans;
Tree<int> t;
set<int> low, high;

ll get(ll l, ll r) {
	return (l+r)*(r-l+1)/2;
}

void norm() {
	bool ok=0;
	while(!ok) {
		ok=1;
		while(low.size()<high.size()) {
			int x=*high.begin();
			high.erase(high.begin());
			low.insert(x);
			ans-=2*x;
		}
		while(high.size()+1<low.size()) {
			int x=*low.rbegin();
			low.erase(--low.end());
			high.insert(x);
			ans+=2*x;
		}
		while(!high.empty()&&*low.rbegin()>*high.begin()) {
			ok=0;
			int x=*low.rbegin(), y=*high.begin();
			low.erase(--low.end()), high.erase(high.begin());
			low.insert(y), high.insert(x);
			ans+=2*x-2*y;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i], b[a[i]]=i;
	for (int i=0; i<n; ++i) {
		int x=b[i];
		ans+=i-t.order_of_key(x);
		t.insert(x);
		low.insert(x);
		ans-=x;
		norm();
		ll m=*low.rbegin();
		cout << ans+get(m-low.size()+1, m)-get(m+1, m+high.size()) << " ";
	}
	return 0;
}