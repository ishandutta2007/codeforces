#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1007, mod = 998244353;
int n, p[N][N], r[N][N], f[N]; //  i  j  
bool vis[N], ok[N];
int find (int x) {
	return f[x] == x ? x : f[x] = find (f[x]);
}
set < int > st[N][N];
void Main () {
	cin >> n;
	L(i, 1, n * 2) f[i] = i;
	L(i, 1, n) L(j, 1, n) st[i][j].clear (), r[i][j] = 0;
	L(i, 1, n * 2) vis[i] = ok[i] = false; 
	L(i, 1, n * 2) L(j, 1, n) cin >> p[i][j], st[j][p[i][j]].insert(i);
	int cnt = 0, ns = 1;
	queue < int > q;
	while (cnt != n * 2) {
		L(i, 1, n) L(j, 1, n) if(sz(st[i][j]) == 1) 
			q.push(*st[i][j].begin()), ok[*st[i][j].begin()] = true;
		while (!q.empty()) {
			int l = q.front();
			q.pop(); 
			if(vis[l]) continue;
//			cout << "insert " << l << " : " << ok[l] << "\n";
			vis[l] = true;
			cnt += 1;
			L(i, 1, n) st[i][p[l][i]].erase (l);
			if(!ok[l]) {
				L(i, 1, n) if(sz(st[i][p[l][i]]) == 1 && !r[i][p[l][i]]) 
					q.push(*st[i][p[l][i]].begin()), ok[*st[i][p[l][i]].begin()] = true;
			} else {
				L(i, 1, n) {
					r[i][p[l][i]] = true;
					for (const int &t : st[i][p[l][i]]) 
						q.push(t), ok[t] = false;
				}
			}
		}
		if(cnt == n * 2) break;
		L(i, 1, n * 2) if(!vis[i]) {
			q.push(i), ok[i] = true;
			break;
		}
		ns = (ll) ns * 2 % mod;	
	}
	cout << ns << '\n';
	L(i, 1, n * 2) if(ok[i]) 
		cout << i << ' ';
	cout << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}