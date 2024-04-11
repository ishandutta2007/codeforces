#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define mkp make_pair
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
int n, m, f[N];
int rmain() {
	int msk = (1 << 30) - 1;
	cin >> n;
	L(i, 1, n) cin >> f[i], msk &= f[i];
	int cnt = 0, ns = 1;
	L(i, 1, n) if(f[i] == msk) ++cnt;
	ns = (ll) cnt * (cnt - 1) % mod;
	L(i, 1, n - 2) ns = (ll) ns * i % mod;
	cout << ns << "\n";
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
}