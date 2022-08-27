#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 5007;
int n, p[N];
ll a[N], b[N]; 
int G[N][N];
int calc(int l1, int r1, int l2, int r2) {
	return G[r1][r2] + G[l1 - 1][l2 - 1] - G[r1][l2 - 1] - G[l1 - 1][r2];
}
void Main () {
	cin >> n ;
	L(i, 1, n) cin >> p[i];
	me(a, 0);
	me(b, 0);
	ll ns = 0;
	L(i, 1, n) 
		L(j, 1, n) 
			G[i][j] = 0;  
	L(i, 1, n) 
		L(j, i + 1, n) 
			G[i][j] = p[i] > p[j];
	L(i, 1, n) 
		L(j, 1, n) 
			G[i][j] += G[i - 1][j];
	L(i, 1, n) 
		L(j, 1, n) 
			G[i][j] += G[i][j - 1];
	L(i, 1, n) 
		L(j, i + 2, n) 
			if(p[i] < p[j]) {
				ns += calc(i + 1, j - 1, j + 1, n);
			}
	cout << ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}