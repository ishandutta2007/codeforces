#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7;
int k, n;
int f[N][N];
void Main() {
	cin >> n >> k;
	L(i, 0, n) f[1][i] = 1;
	L(i, 2, k) {
		int sum = 1;
		L(j, 0, n) {
			if(j) (sum += f[i - 1][n - j]) %= mod;
			f[i][j] = sum;
		}
	}
	cout << f[k][n] << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}