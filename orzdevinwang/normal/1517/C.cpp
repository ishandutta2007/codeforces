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
const int N = 555;
int n, m, a[N][N], z[N];
void rmain() {
	cin >> n;
	L(i, 1, n) cin >> a[i][i], z[i] = a[i][i];
	L(k, 1, n - 1) {
		int o = 0;
		L(j, 1, n - k + 1) if(z[j] == k) o = j; 
		L(j, o + 1, n - k + 1) 
			z[j - 1] = z[j];
		L(j, 1, n - k) 
			a[k + j][j] = z[j];
	}
	L(i, 1, n) {
		L(j, 1, i) cout << a[i][j] << " ";
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	rmain();
	return 0;
}