#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define Tree tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

int n, m, ans[200000], a[200000];
pair<int, int> p[200000];
Tree t;

struct Query {
	int k, p, ind;
} q[200000];
bool operator< (Query x, Query y) {return x.k<y.k;}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], p[i].first=a[i], p[i].second=i;
	sort(p, p+n, [](pair<int, int> x, pair<int, int> y) {return x.first==y.first?x.second<y.second:x.first>y.first; });
	cin >> m;
	for (int i=0; i<m; ++i)
		cin >> q[i].k >> q[i].p, q[i].ind=i;
	sort(q, q+m);

	int j=0;
	for (int i=0; i<m; ++i) {
		Query c=q[i];
		while(j<c.k) {
			t.insert(p[j].second);
			++j;
		}
		ans[c.ind]=a[*t.find_by_order(c.p-1)];
	}
	for (int i=0; i<m; ++i)
		cout << ans[i] << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/