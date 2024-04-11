#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 21, inf = 1e7;
int n, k, a[1 << N], pre[1 << N], ns, cs[1 << N];
inline int cmax (int x, int y) { if(x == -1 || y == -1) return x == -1 ? y : x; return a[x] > a[y] ? x : y; }
bool E[1 << N][N];
void UPD (int x) {
	cs[x] = -1;
	L(i, 0, n - 1) if(E[x][i]) {
		int nx = cmax(cs[x], x ^ (1 << i));
		if(nx != cs[x]) 
			pre[x] = x ^ (1 << i), cs[x] = x ^ (1 << i);
	} 
}
int teshu[1 << N], g;
void change (int u, int v){
	int t = u ^ v;
	t = log2(t), E[u][t] ^= 1, E[v][t] ^= 1;
}
bool op[1 << N], vis[1 << N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie (0);
	cin >> n >> k;
	L(i, 0, (1 << n) - 1) cin >> a[i], op[i] = op[i >> 1] ^ (i & 1), cs[i] = -1;
	L(i, 0, (1 << n) - 1) if(!op[i]) L(j, 0, n - 1) E[i][j] = true;
	L(i, 0, (1 << n) - 1) if(!op[i]) UPD(i);
	while (k--) {
		int x = -1, r = -1;
		L(i, 0, (1 << n) - 1) if(!op[i] && cs[i] != -1 && (x == -1 || a[i] + a[cs[i]] >= r)) x = i, r = a[i] + a[cs[i]];
		if(x == -1 || a[x] + a[cs[x]] <= 0) break;
		ns += a[x], ns += a[cs[x]];
//		cout << x << " " << cs[x] << "\n"; 
		int rn = x;
		while (rn != cs[x]) 
			change (rn, pre[rn]), rn = pre[rn];
		a[cs[x]] = a[x] = -inf;
		teshu[++g] = x, teshu[++g] = cs[x];
		cs[cs[x]] = -1, cs[x] = -1;
		L(i, 1, g) {
			int x = teshu[i];
			L(j, 0, n - 1) {
				int v = x ^ (1 << j);
				cs[v] = -1;
				if(!op[v]) UPD(v);
			}
		}
		L(i, 1, g) {
			int u = teshu[i];
			if(op[u] == 1) cs[u] = pre[u] = -1;
			else pre[u] = -1, UPD(u);
		}
		L(i, 1, g) vis[teshu[i]] = false;
		L(i, 1, g) {
			int x = -1;
			L(j, 1, g) if(!vis[teshu[j]]) x = teshu[j];
			L(j, 1, g) if(!vis[teshu[j]] && cmax(cs[x], cs[teshu[j]]) != cs[x]) x = teshu[j]; 
			vis[x] = true;
			L(j, 0, n - 1) if(!E[x][j]) {
				int v = x ^ (1 << j);
				int nx = cmax(cs[x], cs[v]);
				if(nx != cs[v]) 
					pre[v] = x, cs[v] = cs[x];
			}
		}
	}
	cout << ns << "\n"; 
	return 0;
}