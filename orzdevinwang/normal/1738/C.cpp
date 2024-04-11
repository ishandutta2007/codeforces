#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1007;
int n, k, a[N];
int A[N][N][2], B[N][N][2], c0, c1;
void Main() {
	cin >> n, c0 = c1 = 0;
	L(i, 1, n) cin >> a[i], a[i] &= 1, c0 += a[i] == 0, c1 += a[i] == 1;
	if(A[c0][c1][0]) cout << "Alice\n";
	else cout << "Bob\n";
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	me(A, 0), me(B, 0);
	A[0][0][0] = 1, B[0][0][1] = 1; 
	L(i, 0, 1000) {
		L(j, 0, 1000) if(i || j) L(k, 0, 1) {
			if(i && !B[i - 1][j][k]) A[i][j][k] = true; 
			if(j && !B[i][j - 1][k ^ 1]) A[i][j][k] = true; 
			if(i && !A[i - 1][j][k]) B[i][j][k] = true; 
			if(j && !A[i][j - 1][k]) B[i][j][k] = true; 
		}
	}
//	cout << A[0][3][0] << '\n';
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}