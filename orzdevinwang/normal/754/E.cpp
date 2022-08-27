// George1123 /qiang, SegmentTree /no 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 404;
int n, m, r, c, vis[N][N];
char a[N][N], b[N][N];
bitset<N> bs[26][N], ans[N];
int get(int x) { return (x % m + m - 1) % m + 1; }
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) scanf("%s", a[i] + 1);
	L(i, 1, n) L(j, 1, m) bs[a[i][j] - 'a'][i][j] = 1;
	scanf("%d%d", &r, &c);
	L(i, 1, r) scanf("%s", b[i] + 1);
	L(i, 1, n) L(j, 1, m) ans[i][j] = 1;
	L(x, 1, r) L(y, 1, c) if(b[x][y] != '?') 
		L(i, 1, n) ans[(i - x % n + n) % n + 1] &= ((bs[b[x][y] - 'a'][i] >> ((y - 1) % m)) | (bs[b[x][y] - 'a'][i] << (m - (y - 1) % m)));
	L(i, 1, n) L(j, 1, m) printf("%d%s", (int)ans[i][j], j == m ? "\n" : "");
	return 0;
}