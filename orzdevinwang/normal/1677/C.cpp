#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 2e6 + 7;
int n, m, pa[N], pb[N], p[N];
bool vis[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> pa[i];
	L(i, 1, n) cin >> pb[i], p[pa[i]] = pb[i], vis[i] = false;
	int cs = 0;
	L(i, 1, n) if(!vis[i]) {
		int u = i, cnt = 1;
		vis[u] = true;
		while(p[u] != i) cnt += 1, u = p[u], vis[u] = true;
		cs += cnt / 2;
	}
//	cout << "cs = " << cs << endl;
	cout << (ll) cs * (n - cs) * 2 << '\n'; 
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}