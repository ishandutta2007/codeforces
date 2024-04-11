#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
using namespace std;
const int N = 2e3 + 7;
void Max(int &x, int y) { if(x < y) x = y;}
void Min(int &x, int y) { if(x > y) x = y;}
int U, D, L, R;
int a[N][2], b[N][2];
int f[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	L(i, 1, 4) cin >> a[i][0] >> a[i][1];
	L(i, 1, 4) cin >> b[i][0] >> b[i][1];
	D = L = N, U = R = -N;
	L(i, 1, 4) Max(U, a[i][1]), Min(D, a[i][1]), Max(R, a[i][0]), Min(L, a[i][0]);
	L(i, L, R) L(j, D, U) f[i + 200][j + 200] = 1;
	D = L = N, U = R = -N;
	L(i, 1, 4) Max(U, b[i][1]), Min(D, b[i][1]), Max(R, b[i][0]), Min(L, b[i][0]);
	int mid = (L + R) >> 1, dim = (U + D) >> 1;
	L(i, L, mid) L(j, dim - (i - L), dim + (i - L)) if(f[i + 200][j + 200]) return cout << "YES\n", 0;
	L(i, mid, R) L(j, dim - (R - i), dim + (R - i)) if(f[i + 200][j + 200]) return cout << "YES\n", 0;
	cout << "NO\n";
	return 0;
}