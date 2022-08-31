#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 33;
int n, m, vis[N][N]; 
void Main () {
	cin >> n >> m;
	memset(vis, 0, sizeof(vis));
	L(i, 1, (m + 1) / 2) vis[1][i * 2 - 1] = true;
	L(i, 1, (n + 1) / 2) vis[i * 2 - 1][1] = true;
	
	L(i, 1, (m - 1) / 2) vis[n][m + 2 - i * 2] = true;
	L(i, 1, (n - 1) / 2) vis[n + 2 - i * 2][m] = true; 
	
	L(i, 1, n) {
		L(j, 1, m) cout << vis[i][j];
		cout << "\n";
	}
	cout << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main(); 
	return 0;
}