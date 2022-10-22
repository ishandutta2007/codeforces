#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, q, p[600005], pre[600005], idx[600005], pos[600005];

ll val[600005];

ll par[600005][20];

vector<ll> v[600005];

ll findset(int x){
	return (p[x] == x) ? x : p[x] = findset(p[x]);
}

ll cur = 0;

void dfs(int x){
	pre[x] = cur;
	idx[cur++] = x;
	for (int i=1; i<=19; i++){
		par[x][i] = par[par[x][i-1]][i-1];
	}
	for (auto it : v[x]){
		dfs(it);
	}
	pos[x] = cur-1;
}

ll lca(int x, int y){
	ll a = min(pre[x], pre[y]), b = max(pre[x], pre[y]);
	if (pre[x] <= a && pos[x] >= b) return x;
	for (int i=19; i>=0; i--){
		ll c = par[x][i];
		if (c == 0) continue;
		if (pre[c] <= a && pos[c] >= b) continue;
		x = c;
	}
	return par[x][0];
}

ll arr[600005], curt = 1;

struct node{
	int s, e, m;
	ll val, val1, lazy;
	node *l, *r;
	node (int ns, int ne): s(ns), e(ne), m((ns+ne)/2), lazy(0){
		if (s == e) val1 = arr[s], val = -1;
		else {
			l = new node(s, m);
			r = new node(m+1, e);
			val = -1;
			val1 = max(l->val1, r->val1);
		}
	}
	ll value(){
		if (!lazy) return val;
		if (s == e){
			if (lazy== 1) return val1;
			else return -1;
		}
		if (lazy == 1) val = val1;
		else val = -1;
		
		l->lazy = lazy, r->lazy = lazy;
		
		lazy = 0;
		return val;
	}
	void update(int x, int y, ll v){
	//	cout << s << " " << e << '\n';
		value();
		if (x <= s && y >= e){
			lazy = v;
			return;
		}
		if (x <= m) l->update(x, min(m, y), v);
		if (y > m) r->update(max(x, m+1), y, v);
		val = max(l->value(), r->value());
//		cout << s << " " << e << " " << val << '\n';
	}
} *root, *root1;


vector<pair<ll, pll> > v1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<600005; i++){
		p[i] = i;
	}
	for (int i=1; i<=n-1; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		v1.pb(mp(c,mp(a,b)));
	}
	for (int i=1; i<=n; i++) val[i] = -1;
	sort(v1.begin(), v1.end());
	ll cnt = n + 1;
	for (auto it : v1){
		auto x = it.first, y = findset(it.second.first), z = findset(it.second.second);
		val[cnt] = x;
		par[y][0] = par[z][0] = cnt;
		v[cnt].pb(y), v[cnt].pb(z);
		p[y] = p[z] = cnt++;
		//cout << p[y] << " " << p[z] << "\n"; 
	}
	
	par[2*n-1][0] = 0;
	dfs(2*n-1);
	
	for (int i=1; i<=n; i++){
		arr[i] = pre[i];
	//	cout << pre[i] << "\n";
		
	}
	root = new node(1, n);
	for (int i=1; i<=n; i++){
		arr[i] = 3*n - arr[i];
	}
	root1 = new node(1, n);
	while(q--){
		ll x, y, z;
		cin >> x;
		if (x != 3){
			cin >> y >> z;
			root->update(y, z, x);
			root1->update(y, z, x);
		}
		else {
			cin >> y;
			ll t1 = root->value(), t2 = root1->value();
			if (t2 != -1) t2 = 3*n - t2;
		//	cout << t1 << " " << t2 << '\n';
			ll ans = -1;
			if (t1 != -1) ans = max(val[lca(idx[t1], y)], ans);
			if (t2 != -1) ans = max(val[lca(idx[t2], y)], ans);
			cout << ans << '\n';
		}
	}
}