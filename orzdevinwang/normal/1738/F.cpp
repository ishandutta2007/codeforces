#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, d[N], ord[N];
bool vis[N];
int f[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void Main() {
	cin >> n;
	L(i, 1, n) f[i] = i, vis[i] = false;
	L(i, 1, n) cin >> d[i], ord[i] = i;
	sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		return d[x] > d[y]; 
	});
	L(p, 1, n) if(!vis[ord[p]]) {
		int u = ord[p];
		vis[u] = true;
		L(i, 1, d[u]) {
			cout << "? " << u << endl;
			int w;
			cin >> w;
			f[find(u)] = find(w);
			if(vis[w]) break ;
			vis[w] = true;
		}
	}
	cout << "! ";
	L(i, 1, n) cout << find(i) << ' ';
	cout << endl;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}