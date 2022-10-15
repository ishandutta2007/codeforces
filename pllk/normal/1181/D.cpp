#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;


int n, m, q;
int c[505050];
vector<pair<int,int>> v;
int p[505050];
ll z[505050];
int r[505050];
indexed_set w;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		c[a]++;
	}
	for (int i = 1; i <= m; i++) {
		v.push_back({c[i],i});
	}
	sort(v.begin(),v.end());
	int k = 0;
	ll s = 0;
	for (int i = 0; i < m-1; i++) {
		if (v[i].first != v[i+1].first) {
			int d = v[i+1].first-v[i].first;
			p[k] = i+1;
			s += d*(ll)(i+1);
			k++;
			z[k] = s;
		}
	}
	vector<pair<ll,int>> qq;
	for (int i = 1; i <= q; i++) {
		ll x;
		cin >> x;
		qq.push_back({x,i});
	}
	sort(qq.begin(),qq.end());
	int f = 0;
	for (int i = 0; i < p[0]; i++) {
		w.insert(v[i].second);
	}
	for (int i = 0; i < q; i++) {
		ll x = qq[i].first;
		x -= (n+1);
		if (x >= z[k]) {
			x -= z[k];
			r[qq[i].second] = x%m+1;
			continue;
		}
		while (f+1 <= k && z[f+1] <= x) {
			f++;
			for (int j = p[f-1]; j < p[f]; j++) {
				w.insert(v[j].second);
			}
		}
		x -= z[f];
		r[qq[i].second] = *w.find_by_order(x%p[f]);
	}
	for (int i = 1; i <= q; i++) {
		cout << r[i] << "\n";
	}
}