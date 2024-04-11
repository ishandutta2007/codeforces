#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 1e2 + 7, M = 10005;
int n, m, k;
bitset < M > f[N][N];
void Main() {
	cin >> n >> m >> k;
	if(f[n][m][k]) cout << "YES\n";
	else cout << "NO\n";
}
void init() {
	f[1][1].set(0);
	L(i, 1, 100) L(j, 1, 100) f[i + 1][j] |= f[i][j] << j, f[i][j + 1] |= f[i][j] << i;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	init();
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}