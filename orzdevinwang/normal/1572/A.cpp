#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 5e5 + 7;
int n, m, dp[N], ehd[N], ev[N], enx[N], eid, deg[N];
void eadd (int  u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, deg[v] += 1, ehd[u] = eid;
}
void Main () {
	int cnt = 0; 
	eid = 0;
	L(i, 1, n) ehd[i] = deg[i] = 0;
	cin >> n;
	L(i, 1, n) {
		int P; 
		cin >> P; 
		while (P--) {
			int x;
			cin >> x;
			eadd (x, i);
		}
	}
	queue < int > q;
	L(i, 1, n) dp[i] = -1;
	L(i, 1, n) if(deg[i] == 0) dp[i] = 1, q.push(i);
	while(!q.empty()) {
		cnt += 1;
		int u = q.front();
		q.pop();
		for (int i = ehd[u]; i; i = enx[i]) {
			int v = ev[i];
			dp[v] = max (dp[v], dp[u] + (u > v));
			deg[v] -= 1;
			if(deg[v] == 0) q.push(v);
		}
	}
	if (cnt != n) return cout << -1 << "\n", void (); 
	int ret = -1;
	L(i, 1, n) ret = max(ret, dp[i]);
	cout << ret << "\n"; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}