#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2007;
int n, k, ds[N][10];
string g[N];
string s[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", 
"1101111", "1010010", "1111111", "1111011"};
int Dis (string a, string b) {
	int ret = 0;
	L(i, 0, 6) {
		if(a[i] == '1' && b[i] == '0') ret = 2333; 
		if(a[i] == '0' && b[i] == '1') ret += 1;
	}
	return ret;
}
bitset < N > DP[N];
int val[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	L(i, 1, n) cin >> g[i];
	L(i, 1, n) L(j, 0, 9) ds[i][j] = Dis (g[i], s[j]);
	DP[n + 1].set (0);
	R(i, n, 1) L(j, 0, 9) DP[i] |= DP[i + 1] << ds[i][j];
	if(DP[1][k] == 0) return cout << -1 << "\n", 0;
	L(i, 1, n) {
		R(j, 9, 0) if(k >= ds[i][j] && DP[i + 1][k - ds[i][j]]) {
			val[i] = j;
			k -= ds[i][j];
			break ;	
		}
	}
	L(i, 1, n) cout << val[i];
	return 0;
}