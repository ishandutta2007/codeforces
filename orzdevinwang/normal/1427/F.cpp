#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20, mod = 998244353;
int n, a[N], stk[N], len[N], arr[N][3], tp;
int col[N];
vi e[N];
queue < int > q[2][2];
vector < int > vc;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	L(i, 1, n * 3) cin >> a[i], col[a[i]] = 1;
	
	L(i, 1, n * 6) {
		if(!tp || col[stk[tp]] != col[i]) e[stk[tp]].push_back(i), ++ tp, stk[tp] = i, len[tp] = 0;
		else ++len[tp];
		arr[stk[tp]][len[tp]] = i;
		if(len[tp] == 2) -- tp;
	}
	
	for (const int &v : e[0]) q[col[v]][sz(e[v]) ? 1 : 0].push(v);
	L(t, 1, n) L(o, 0, 1) {
		if(sz(q[o][1])) {
			int u = q[o][1].front();
			q[o][1].pop(), vc.push_back(u);
			for (const int &v : e[u]) q[col[v]][sz(e[v]) ? 1 : 0].push(v);
		} else assert(sz(q[o][0])), vc.push_back(q[o][0].front()), q[o][0].pop();
	}
	reverse(vc.begin(), vc.end());
	for (const int &u : vc) cout << arr[u][0] << ' ' << arr[u][1] << ' ' << arr[u][2] << '\n';
	return 0;
}