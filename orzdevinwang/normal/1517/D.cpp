#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 555, K = 12;
int n, m, k, a[N][N], b[N][N], mn[N][N], ns[K][N][N];
void rmain() {
	memset(a, 0x3f, sizeof(a));
	memset(b, 0x3f, sizeof(b));
	cin >> n >> m >> k;	
	L(i, 1, n) L(j, 1, m - 1) cin >> a[i][j];
	L(i, 1, n - 1) L(j, 1, m) cin >> b[i][j];
	if(k % 2 == 1) {
		L(i, 1, n) {
			L(j, 1, m) cout << "-1" << " ";
			cout << "\n";
		}
		return ;
	}
	k >>= 1;
	memset(ns, 0x3f, sizeof(ns));
	L(i, 1, n) L(j, 1, m) ns[0][i][j] = 0;
	L(i, 1, k) {
		L(x, 1, n) L(y, 1, m) {
			ns[i][x][y] = min(ns[i][x][y], ns[i - 1][x - 1][y] + b[x - 1][y]);
			ns[i][x][y] = min(ns[i][x][y], ns[i - 1][x + 1][y] + b[x][y]);
			ns[i][x][y] = min(ns[i][x][y], ns[i - 1][x][y - 1] + a[x][y - 1]);
			ns[i][x][y] = min(ns[i][x][y], ns[i - 1][x][y + 1] + a[x][y]);
		}
	}
	L(i, 1, n) {
		L(j, 1, m) cout << ns[k][i][j] * 2 << " ";
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	rmain();
	return 0;
}