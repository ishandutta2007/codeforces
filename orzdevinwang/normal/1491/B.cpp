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
int n, m, f[N], cnt, u, v;
void Main() {
	int ans;
	cin >> n >> u >> v;
	L(i, 1, n) cin >> f[i];
	bool ok = 1;
	L(i, 1, n - 1) if(abs(f[i] - f[i + 1]) >= 2) return cout << "0\n", void();
	L(i, 1, n - 1) if(f[i] ^ f[i + 1]) ok = 0;
	if(ok) ans = min(u + v, v * 2);
	else ans = min(u, v);
	cout << ans << "\n"; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}