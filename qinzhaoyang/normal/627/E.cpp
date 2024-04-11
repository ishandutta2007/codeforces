#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int N = 3e3 + 10;
typedef long long ll;

int r, c, n, k, p[N], q[N];
pair <int,int> a[N];
vector <pair<int,int> > R[N], C[N];
ll ans, sum, cnt[N];

int main() {
	cin >> r >> c >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		R[a[i].fi].push_back(make_pair(a[i].se, i));
		C[a[i].se].push_back(make_pair(a[i].fi, i));
	}
	for(int i = 1; i <= r; i++) sort(R[i].begin(), R[i].end());
	for(int i = 1; i <= c; i++) sort(C[i].begin(), C[i].end()); 
	for(int u = 1; u <= r; u++) {
		for(int i = 0; i <= n + 1; i++) p[i] = q[i] = cnt[i] = 0;
		int o = 0; ll t = 0; sum = 0;
		for(int i = 1; i <= c; i++) {
			for(auto j : C[i]) if(j.fi >= u)
				p[j.se] = o, q[o] = j.se, o = q[o];
			int j = o; for(int m = 1; m < k; m++) j = p[j];
			if(j) cnt[j]++, sum += a[j].se;
		}
		q[o] = n + 1, p[n + 1] = o;
		for(int d = r; d >= u; d--) {
			ans += sum;
			for(auto i : R[d]) {
				o = i.se; t = cnt[o]; sum -= cnt[o] * a[o].se;
				for(int m = 1; m <= k; m++) {
					o = p[o]; if(!o) break;
					if(m < k) sum += (t - cnt[o]) * a[o].se, swap(t, cnt[o]);
					else sum += t * a[o].se, cnt[o] += t;
				}
				int o1 = p[i.se], o2 = q[i.se];
				q[o1] = o2, p[o2] = o1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}