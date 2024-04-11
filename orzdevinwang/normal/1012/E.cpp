#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int ehd[N], ev[N], enx[N];
void eadd (int u, int v, int eid) {
	enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
int n, s, f[N], r[N], fa[N];
int find (int x) {
	return fa[x] == x ? x : fa[x] = find (fa[x]);
}
void merge (int u, int v) {
	u = find (u);
	v = find (v);
	if(u != v) 
		fa[u] = v;
}
bool vis[N], use[N];
int road[N], tp, to[N];
void DFS (int x) {
	for (int &i = ehd[x], o; i; i = enx[i]) if(!use[i]) o = i, use[i] = true, DFS(ev[i]), road[++tp] = o;
}
int arr[N], atot;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> s;
	L(i, 1, n) cin >> f[i], arr[++atot] = f[i], fa[i] = i;
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) f[i] = lower_bound(arr + 1, arr + atot + 1, f[i]) - arr;
	L(i, 1, n) r[i] = f[i];
	sort(r + 1, r + n + 1);
	L(i, 1, n) 
		if(r[i] != f[i]) 
			s -= 1, merge (f[i], r[i]), vis[r[i]] = vis[f[i]] = true, to[f[i]] = i;
	if (s < 0) 
		return cout << "-1\n", 0;
	vi S;
	L(i, 1, n) if(vis[i] && find(i) == i) S.push_back(to[i]);
	s = min(s, sz(S));
	if(s <= 1) {
		L(i, 1, n) if(f[i] != r[i]) eadd (f[i], r[i], i);
		cout << sz(S) << '\n';
		L(i, 1, n) if(find (i) == i && vis[i]) {
			tp = 0, DFS (i);
			cout << tp << '\n';
			L(j, 1, tp) 
				cout << road[j] << ' ';
			cout << '\n';
		}
	} else {
		cout << sz(S) - s + 2 << '\n';
		S.resize(s);
		R(i, sz(S) - 2, 0) 
			swap(f[S[i]], f[S[i + 1]]), merge (f[S[i]], f[S[i + 1]]);
		cout << sz(S) << '\n';
		L(i, 0, sz(S) - 1) 
			cout << S[i] << ' ';
		cout << '\n';
		L(i, 1, n) if(f[i] != r[i]) eadd (f[i], r[i], i);
		L(i, 1, n) if(find(i) == i && vis[i]) {
			tp = 0, DFS (i);
			// reverse(road + 1, road + tp + 1);
			cout << tp << '\n';
			L(j, 1, tp) 
				cout << road[j] << ' ';
			cout << '\n';
		}
	}
	return 0;
}