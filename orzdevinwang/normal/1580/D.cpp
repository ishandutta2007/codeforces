#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 4007;
int n, m, w[N], tot;
ll f[N * 2][N];
void calc (int &x, int L, int R) {
	x = ++tot;
	if(L > R) return f[x][0] = 0, void ();
//	if(L == R) return f[x][1] = (ll) (m - 1) * w[L], f[x][0] = 0, void();
	int mid = L, ls, rs;
	L(i, L, R) if(w[i] < w[mid]) mid = i;
//	cout << L << ' ' << R << " : " << mid << '\n';
	calc (ls, L, mid - 1);
	calc (rs, mid + 1, R);
	L(a, 0, mid - L) 
		L(b, 0, R - mid) 
			f[x][a + b] = max(f[x][a + b], f[ls][a] + f[rs][b] - (ll) 2 * a * b * w[mid]);
	L(a, 0, mid - L) 
		L(b, 0, R - mid) 
			f[x][a + b + 1] = max(f[x][a + b + 1], 
	f[ls][a] + f[rs][b] - (ll) (2 * a * b + 2 * a + 2 * b + 1) * w[mid] + (ll) m * w[mid]);
//	cout << L << " " << R << " :\n";
//	L(i, 0, R - L + 1) cout << f[x][i] << ' ';
//	cout << "\n\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> w[i]; 
	memset(f, -0x3f, sizeof(f));
	int rt;
	calc (rt, 1, n);
//	L(i, 0, n) cout << f[rt][i] << ' ';
//	cout <<'\n';
	cout << f[rt][m] << '\n';
	return 0;
}