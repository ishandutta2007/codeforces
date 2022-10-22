#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a[1000005], b[1000005], c, arr[1000005];

ll ft[2000005];

void update1(ll x, ll v) {
	for (; x < 2000005; x += x & -x) ft[x] += v;
}

ll query1(int x) {
	ll sum = 0;
	for (; x; x -= x & -x) sum += ft[x];
	return sum;
}


struct node{
	int s, e, m;
	ll val, lazy;
	node *l, *r;
	node (int ns, int ne): s(ns), e(ne), m((ns+ne)/2), lazy(0){
		if (s == e) val = -s-1;
		else {
			l = new node(s, m);
			r = new node(m+1, e);
			val = max(l->val, r->val);
		}
	}
	ll value(){
		if (!lazy) return val;
		if (s == e) return val + lazy;
		val += lazy;
		l->lazy += lazy, r->lazy += lazy;
		lazy = 0;
		return val;
	}
	void update(int x, int y, ll v){
		if (x <= s && y >= e){
			lazy += v;
			return;
		}
		if (x <= m) l->update(x, min(m, y), v);
		if (y > m) r->update(max(x, m+1), y, v);
		val = max(l->value(), r->value());
	}
	ll query(int x, int y){
		value();
		if (x <= s && y >= e) return value();
		ll ret = -2e9;
		if (x <= m) ret = max(ret, l->query(x, min(m, y)));
		if (y > m) ret = max(ret, r->query(max(x, m+1), y));
		return ret;
	}
} *root;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		vector<int> v;
		vector<int> pos[n+m+1];
		for (int i=0; i<n; i++){
			cin >> a[i];
			arr[i] = -1;
			v.pb(a[i]);
		}
		for (int i=0; i<m; i++){
			cin >> b[i];
			v.pb(b[i]);
		}
		sort(b, b+m);
		sort(v.begin(), v.end());
		for (int i=0; i<n; i++){
			a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			pos[a[i]].pb(i);
		}
		for (int i=0; i<m; i++){
			b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
		}
		for (int i=0; i<n+m+3; i++) ft[i] = 0;
		root = new node(0, n-1);
		int cur = 0;
		ll sum = 0;
		ll ans = 0;
		bool gd = false;
		for (int i=0; i<m; i++){
			while (cur < b[i]){
				gd = false;
				for (auto it : pos[cur]){
					root->update(it, n-1, 1 - arr[it]);
					arr[it] = 1;
					sum++;
				}
				cur++;
			}
			if (!gd){
				gd = true;
				for (auto it : pos[cur]){
					root->update(it, n-1, -arr[it]);
					arr[it] = 0;
				}
			}
			ll thing = 0;
			ans += sum - max(thing, root->query(0,n-1));
		}
		for (int i=n-1; i>=0; i--){
		//	cout << a[i] << "\n";
			if (a[i] > 0){
				ans += query1(a[i]);

			}
			update1(a[i]+1, 1);
		}
		cout << ans << "\n";
	}
}