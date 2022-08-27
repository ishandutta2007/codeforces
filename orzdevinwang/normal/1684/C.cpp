#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, O = 5e5;
int n, m, mx[N];
vi a[N];
void Main() {
	cin >> n >> m;
	L(i, 1, n) a[i].resize(m + 1);
	L(i, 1, n) 
		L(j, 1, m) 
			cin >> a[i][j];
	int u = -1, v = -1;
	L(i, 1, n) {
		int mx = 0, p = 0;
		L(j, 1, m) {
			mx = max(mx, a[i][j]);
			if(mx > a[i][j]) p = j;
		}
		if(p) {
			int l = 1, r = p;
			while(a[i][l] <= a[i][r]) ++l;
			if(u == -1) u = l, v = r;
		}
	}
	if(u == -1) u = v = 1;
	L(i, 1, n) swap(a[i][u], a[i][v]);
	L(i, 1, n) 
		L(j, 1, m - 1) 
			if(a[i][j] > a[i][j + 1]) 
				return cout << -1 << '\n', void ();
	cout << u << ' ' << v << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}