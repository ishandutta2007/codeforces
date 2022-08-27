#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
#define i128 __int128
using namespace std;
const int N = 1e6 + 7; 
int n, m, ns[N], tot, f[N], su[N], sv[N], id;
bool vis[N];
ll a[N], x;
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

struct edge {
	int v, id;
} e[N];
bool operator < (edge aa, edge bb) {
	return aa.v < bb.v;
}

priority_queue < pair< ll, int > > q;
set < edge > s[N];
void mg(int u, int v) {
	if(sz(s[u]) > sz(s[v])) swap(u, v);
	s[u].erase(* s[u].lower_bound(edge{v, 0}));
	s[v].erase(* s[v].lower_bound(edge{u, 0}));
	vis[u] = true, a[v] = a[v] + a[u] - x;
	for(edge x : s[u]) {
		edge d = * s[x.v].lower_bound(edge{u, 0});
		s[x.v].erase(d), s[x.v].insert(edge{v, d.id});
		
		auto z = s[v].lower_bound(edge {x.v, 0});
		if(z == s[v].end() || (*z).v != x.v) s[v].insert(x);
	} 
	q.push(make_pair(a[v], v));
} 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;
	ll sum = 0;
	L(i, 1, n) cin >> a[i], sum += a[i];
	if(sum < (n - 1) * x) return cout << "NO\n", 0;
	sum = 0;
	L(i, 1, n) f[i] = i;
	L(i, 1, m) {
		cin >> su[i] >> sv[i];
		if(find(su[i]) != find(sv[i])) 
			s[su[i]].insert(edge {sv[i], i}), s[sv[i]].insert(edge {su[i], i}), 
			f[find(su[i])] = sv[i], ++sum; 
	}
	if(sum != n - 1) return cout << "NO\n", 0;
	L(i, 1, n) q.push(make_pair(a[i], i));
	while(tot < n - 1) {
		if(q.empty()) return 0;
		int u = q.top().second; 
		ll z = q.top().first;
		q.pop();
		if(vis[u] || a[u] != z) continue;
		edge t = * s[u].rbegin();
		if(vis[t.v]) return 0;
		ns[++tot] = t.id, mg(u, t.v);
	}
	cout << "YES\n";
	L(i, 1, tot) cout << ns[i] << "\n";
	return 0;
}