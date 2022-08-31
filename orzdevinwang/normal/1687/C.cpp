#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N], b[N], l[N], r[N];

ll sz[N];
void add(int x, int w) {
	for(; x <= n; x += x & -x) 
		sz[x] += w;
}
ll query(int x) {
	ll ret = 0;
	for (; x; x -= x & -x) 
		ret += sz[x];
	return ret;
}

int f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
inline bool get(int x) {
	return !query(r[x]) && !query(l[x] - 1);
}

vi tc[N];
bool op[N]; 

void Main() {
	cin >> n >> m;
	
	L(i, 1, n) sz[i] = 0, tc[i].clear();
	L(i, 1, m) op[i] = true;
	
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cin >> b[i], a[i] -= b[i];
	L(i, 1, n) add(i, a[i]);
	L(i, 1, n + 1) f[i] = i;
	
	priority_queue < pair < int, int > > q;
	L(i, 1, m) {
		cin >> l[i] >> r[i];
		tc[l[i]].emplace_back(i);
		tc[r[i]].emplace_back(i);
		if(get(i)) 
			q.push(make_pair(r[i] - l[i] + 1, i));
	}
	
	while(!q.empty()) {
		int i = q.top().second;
		assert(get(i));
		op[i] = false;
		q.pop();
		int xl = 1e9, xr = 0;
		for(int u = find(l[i]); u <= r[i]; u = find(u)) {
			f[u] = u + 1;
			add(u, -a[u]);
			a[u] = 0;
			xl = min(xl, u);
			xr = max(xr, u);
		}
		L(i, xl, xr) 
			for(const int &u : tc[i]) 
				if(get(u) && op[u]) 
					q.push(make_pair(r[u] - l[u] + 1, u));
	} 
	L(i, 1, n) 
		if(a[i] != 0) 
			return cout << "NO\n", void ();
	cout << "YES\n";
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}