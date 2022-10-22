#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define Tree tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int mxN=500001;
int n, m, q, ans[mxN];
int cnt[mxN], offset=0, cur=0;
pair<ll, int> qry[mxN];
Tree s[mxN];

void merge(int i) {
	if (s[i+1].size()<s[i].size()) s[i].swap(s[i+1]);
	for (const int &x : s[i]) s[i+1].insert(x);
	s[i].clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	for (int i=0, a; i<n; ++i) cin >> a, ++cnt[a];
	for (int i=0; i<q; ++i) cin >> qry[i].first, qry[i].second=i;
	for (int i=1; i<=m; ++i) s[cnt[i]].insert(i);
	sort(qry, qry+q);

	for (int i=0; i<q; ++i) {
		ll k=i==0?qry[i].first-n-1:qry[i].first-qry[i-1].first;
		//cout << k << ' ' << cur << ' ' << s[cur].size() << ' ' << offset << '\n';
		while(cur<n&&k+offset>=s[cur].size()) {
			k-=s[cur].size()-offset;
			offset=0;
			merge(cur);
			++cur;
		}
		if (cur==n) {
			assert(s[cur].size()==m);
			k%=m;
			offset=(offset+k)%m;
			ans[qry[i].second]=*s[cur].find_by_order(offset);
		}
		else {
			offset+=k;
			assert(offset<s[cur].size());
			ans[qry[i].second]=*s[cur].find_by_order(offset);
		}
	}
	for (int i=0; i<q; ++i)
		cout << ans[i] << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/