#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
int n, m, dp[N], f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	int S = sqrt(n);
	R(i, (n - 1) / S + 1, 1) L(j, 1, S) if((i - 1) * S + j <= n) cout << (i - 1) * S + j << " ";
	cout << endl;
	return 0;
}