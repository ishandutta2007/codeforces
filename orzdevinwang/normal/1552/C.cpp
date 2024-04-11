#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1e5 + 7;
int n, k, mat[N], f[N], tp;
void Main () {
	cin >> n >> k;
	L(i, 1, k) {
		int u, v;
		cin >> u >> v;
		mat[u] = v, mat[v] = u;
	}
	tp = 0;
	L(i, 1, n * 2) if(!mat[i]) f[++tp] = i;
	L(i, 1, n - k) 
		mat[f[i]] = f[i + (n - k)], 
		mat[f[i + (n - k)]] = f[i];
//	L(i, 1, n * 2) cout << mat[i] << ' ';
//	cout << '\n';
	int ns = 0;
	L(i, 1, n * 2) if(i < mat[i]) L(j, i + 1, n * 2) if(j < mat[j] && mat[i] > j && mat[i] < mat[j]) ++ns;
	cout << ns << "\n";
	L(i, 1, n * 2) mat[i] = 0;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}