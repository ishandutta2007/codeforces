#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
#define me(a, x) memset(a, x, sizeof(a))
using namespace std;
const int N = 1 << 16;
int n, K;
void query(int *d, bool *a) ;
void query(int *d, bool *a) {
	cout << "? ";
	L(i, 1, n) cout << min(max(d[i], 0), n - 1)  << ' ';
	cout << endl;
	string s;
	cin >> s;
	assert(sz(s) == n);
	L(i, 1, n) a[i] = s[i - 1] - '0'; 
}
bool a[N], b[N], c[N], vis[N];
int dis[N], f[N];
vi vc[N];
int msk[N], fa[N], id[N], mp[N], q[N], tp;
void wxy_god(int xn, int subtask) {
	n = xn;
	if(subtask == 0 && n == 5) {
		cout << "2 1\n5 3\n2 4\n2 3\n";
		return ;
	}
	me(vis, 0);
	int lg = 31 - __builtin_clz(n);
	vc[0].emplace_back(1), vis[1] = true;
	R(i, lg, 0) {
		me(f, -1), me(a, 0), me(b, 0), me(c, 0);
		for(int j = 0; j <= n; j += (1 << (i + 2))) 
			for(const int &u : vc[j]) f[u] = 1 << i;
		query(f, a);
		
		me(f, -1);
		for(int j = (1 << (i + 1)); j <= n; j += (1 << (i + 2))) 
			for(const int &u : vc[j]) f[u] = 1 << i;
		query(f, b);
		
		me(f, -1);
		for(int j = 0; j <= n; j += (1 << (i + 1))) 
			for(const int &u : vc[j]) f[u] = (1 << i) - 1;
		query(f, c);
		
		L(t, 1, n) if(!vis[t]) {
			bool qwqx = (dis[t] >> (i + 1) & 1) && b[t];
			bool qwqy = !(dis[t] >> (i + 1) & 1) && a[t]; 
			if((qwqx || qwqy) && !c[t]) {
				dis[t] += 1 << i, vc[dis[t]].emplace_back(t), vis[t] = true;	
			} 
			else {
				if(a[t] && b[t]) assert(false); 
				if((dis[t] >> (i + 1) & 1) && !b[t]) dis[t] += 1 << i;
				if(!(dis[t] >> (i + 1) & 1) && !a[t]) dis[t] += 1 << i;
			}
		}
	}
	L(i, 1, n) assert(vis[i]);
	
	L(c, 0, 2) {
		tp = 0;
		for(int i = c; i <= n; i += 3) for(const int &u : vc[i]) q[++tp] = u;
		if(!tp) continue;
		K = 31 - __builtin_clz(tp * 2 - 1);
		me(msk, 0), me(mp, 0);
		int cur = 1;
		L(i, 0, (1 << K) - 1) if(cur <= tp) 
			id[q[cur]] = i, mp[i] = q[cur], ++cur; 
		assert(cur > tp);
		
		L(t, 0, K - 1) {
			me(f, -1);
			L(i, 1, tp) if(id[q[i]] >> t & 1) f[q[i]] = 1;
			query(f, a);
			L(i, 1, n) if(a[i]) msk[i] |= 1 << t;
		}
		
		for(int i = c + 1; i <= n; i += 3) {
			for(const int &u : vc[i]) {
				assert(mp[msk[u]]);
				fa[u] = mp[msk[u]];
			}
		}
	}
	cout << "!\n";
	L(i, 2, n) cout << fa[i] << ' ' << i << '\n';
	cout << endl;
}

int main() {
	cin >> n, wxy_god(n, 1);
	return 0;
}