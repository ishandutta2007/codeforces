#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mx = 1000002;
int n, q, a[N], f[N], p[N], tot, vis[N]; 
bool Prime[N];
int find (int x) { return f[x] == x ? x : f[x] = find (f[x]); } 
set < int > st[N >> 1];
vi s[N >> 1];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 1, n) cin >> a[i], vis[a[i]] = i;
	
	L(i, 2, mx) Prime[i] = true;
	L(i, 2, mx) L(j, 2, mx / i) Prime[i * j] = false;
	L(i, 2, mx) if(Prime[i]) p[++tot] = i;
	
	L(i, 1, tot + n) f[i] = i; 
	
	L(i, 1, tot) L(j, 1, mx / p[i]) if(vis[p[i] * j]) 
		f[find(vis[p[i] * j] + tot)] = find(i);	
	
	L(i, 1, tot) L(j, 1, mx / p[i]) if(vis[p[i] * j - 1]) 
		st[find(i)].insert(find(vis[p[i] * j - 1] + tot));
		
	L(i, 1, tot) L(j, 1, mx / p[i]) if(vis[p[i] * j - 1]) 
		s[vis[p[i] * j - 1]].push_back(find(i));
	
	L(i, 1, n) for(const int &u : s[i]) for(const int &v : s[i]) 
		if(u < v) st[u].insert(v); 
	
	while (q--) {
		int u, v;
		cin >> u >> v;
		if(find(u + tot) == find(v + tot)) {
			cout << 0 << "\n";
			continue;
		}
		
		int x = find(u + tot), y = find(v + tot);
		if(st[x].find(y) != st[x].end() || st[y].find(x) != st[y].end()) 
			cout << 1 << "\n";
		else cout << 2 << "\n";
	}
	return 0;
}