#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, mx = 1000, f[N], g[N], vis[N], ok, ans = 1e9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(f, 0x3f, sizeof(f));
	memset(g, 0x3f, sizeof(g));
	L(i, 1, m) {
		int x; 
		cin >> x;
		vis[x] = true;
	}
	if(vis[n]) return cout << "1\n", 0;
	L(i, 1, n) L(j, 1, 1000 - n) if(vis[n - i] && vis[n + j]) {
		int g = __gcd(i, j);
		ok = true, mx = min(mx, (i + j) / g);
	} 
	if(!ok) return cout << "-1\n", 0;
	mx *= 500;
	f[0] = g[0] = 0;
	L(i, 1, n) if(vis[n - i]) 
		L(j, 0, mx - i) f[j + i] = min(f[j + i], f[j] + 1); 
	L(i, 1, 1000 - n) if(vis[n + i]) 
		L(j, 0, mx - i) g[j + i] = min(g[j + i], g[j] + 1);
	L(i, 1, mx) ans = min(ans, f[i] + g[i]);
	if(ans > 1e7) cout << "-1\n";
	else cout << ans << "\n"; 
	return 0;
}