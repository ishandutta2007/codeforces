#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1e5 + 7;
int n, a[N], cnt = 0;
void dfs (int x, int res) {
	if(x == n + 1) {
		cnt += res == 0;
		return ;
	}
	dfs (x + 1, res + a[x]);
	dfs (x + 1, res);
	dfs (x + 1, res - a[x]) ;
}
void Main () {
	cnt = 0;
	cin >> n;
	L(i, 1, n) cin >> a[i];
	dfs (1, 0);
	if(cnt == 1) cout << "NO\n";
	else cout << "YES\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}