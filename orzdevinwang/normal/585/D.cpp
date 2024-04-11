#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 10;
int n, B, x[N], y[N], z[N];
int sx, sy, sz;
map < pair < int, int >, int > mp;
char ox[N], oy[N];
void dfs1 (int o) {
	if(o == B + 1) {
		auto u = make_pair(sy - sx, sz - sx);
		if(!mp.count(u)) mp[u] = sx;
		else mp[u] = max (mp[u], sx);
		return ;
	}
	sx += x[o], sy += y[o], dfs1 (o + 1), sx -= x[o], sy -= y[o];
	sx += x[o], sz += z[o], dfs1 (o + 1), sx -= x[o], sz -= z[o];
	sy += y[o], sz += z[o], dfs1 (o + 1), sy -= y[o], sz -= z[o];
}
int ndx, ndy, ndd, op[N], ns[N];
ll mx = -1e18;
void dfs2 (int o) {
	if(o == n + 1) {
		if(mp.count ({sx - sy, sx - sz})) {
			ll u = mp[{sx - sy, sx - sz}] + sx;
			if(u > mx) {
				mx = u;
				ndx = sx - sy;
				ndy = sx - sz;
				ndd = u - sx;
				L(i, B + 1, n) ns[i] = op[i];
			}
		}
		return ;
	}
	op[o] = 1, sx += x[o], sy += y[o], dfs2 (o + 1), sx -= x[o], sy -= y[o];
	op[o] = 2, sx += x[o], sz += z[o], dfs2 (o + 1), sx -= x[o], sz -= z[o];
	op[o] = 3, sy += y[o], sz += z[o], dfs2 (o + 1), sy -= y[o], sz -= z[o];
}
void dfs3 (int o) {
	if(o == B + 1) {
		if(sx == ndd && sy - sx == ndx && sz - sx == ndy) {
			L(i, 1, B) ns[i] = op[i];
		}
		return ;
	}
	op[o] = 1, sx += x[o], sy += y[o], dfs3 (o + 1), sx -= x[o], sy -= y[o];
	op[o] = 2, sx += x[o], sz += z[o], dfs3 (o + 1), sx -= x[o], sz -= z[o];
	op[o] = 3, sy += y[o], sz += z[o], dfs3 (o + 1), sy -= y[o], sz -= z[o];
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n ;
	L(i, 1, n) cin >> x[i] >> y[i] >> z[i];
	B = n >> 1;
	dfs1 (1);
	dfs2 (B + 1);
	if(mx == -1e18) return cout << "Impossible\n", 0;
	dfs3 (1);
	L(i, 1, n) {
		if(ns[i] == 1) cout << "LM\n";
		if(ns[i] == 2) cout << "LW\n";
		if(ns[i] == 3) cout << "MW\n";
	}
	return 0;
}