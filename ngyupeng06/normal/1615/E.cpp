#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, a, b, cnt, cur = 0, p[200005];
ll cmin[200005], cmax[200005], idx[200005];
vector<ll> v[200005];

struct node{
	int s, e, m;
	ll val, lazy, pos;
	node *l, *r;
	node (int ns, int ne): s(ns), e(ne), m((ns+ne)/2), lazy(0), val(0){
		if (s == e) pos = s;
		if (s != e){
			l = new node(s, m);
			r = new node(m+1, e);
			pos = s;
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
		if (l->value() > r->value()){
			pos = l->pos;
			val = l->value();
		}
		else {
			pos = r->pos;
			val = r->value();
		}
	}
	pll query(int x, int y){
		value();
		if (x <= s && y >= e) return mp(value(), pos);
		pll ret = mp(-2e9, -1);
		if (x <= m){
			pll temp = l->query(x, min(m,y));
//			cout << temp.first << " bruh\n";
			if (ret.first < temp.first){
				ret = temp;
			}
		}
		if (y > m){
			pll temp = r->query(max(x, m+1), y);
			if (ret.first < temp.first){
				ret = temp;
			}
		}
		return ret;
	}
} *root;


void dfs(int x, int par, int dp){
	p[x] = par;
	idx[cur] = x;
	cmin[x] = cur++;
	root->update(cmin[x], cmin[x], dp);
//	cout << root->query(0,n-1).first << " tet\n";
	for (auto it : v[x]){
		if (it == par) continue;
		dfs(it, x, dp+1);
	}
	cmax[x] = cur-1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n-1; i++){
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	cnt = 0;
	for (int i=1; i<=n; i++){
		if (v[i].size()==1 && i!=1){
			cnt++;
		}
	}
	if (m >= cnt){
		if (m < n/2) cout << m*(n-m);
		else if (cnt <= n/2){
			cout << (n/2)*(n-n/2);
		}
		else cout << cnt * (n-cnt);
	}
	else {
		root = new node(0,n-1);
		dfs(1,-1, 1);
		ll sum = 0;
		for (int i=0; i<m; i++){
			pll temp = root->query(0,n-1);
//			cout << temp.first << " " << temp.second << "\n";
			sum += temp.first;
			ll cur1 = idx[temp.second];
			for (int j=0; j<temp.first; j++){
				root->update(cmin[cur1], cmax[cur1], -1);
				cur1 = p[cur1];
			}
		}
		ll remm = n - sum;
		if (m >= remm){
			cout << (m-remm)*(n-m-remm);
		}
		else {
			ll ans = 0;
			for (int i=m; i<=remm; i++){
				ans = min(ans, (m-i)*(n-m-i));
			}
			cout << ans;	
		}
	}
}