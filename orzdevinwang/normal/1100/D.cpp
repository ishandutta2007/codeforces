#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 1234;
int x, y, a[N], b[N], c1, c2;
int vis[N][N];
int d[2][2];
void Print() {
	cout << x << " " << y << endl;
	fflush(stdout);
	int k, x, y;
	cin >> k >> x >> y;
	if(k <= 0) exit(0);
	--vis[a[k]][b[k]], a[k] = x, b[k] = y, ++vis[a[k]][b[k]];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> x >> y;
	L(i, 1, 666) cin >> a[i] >> b[i], ++vis[a[i]][b[i]];
	while(x < 500) ++x, Print();
	while(x > 500) --x, Print();
	while(y < 500) ++y, Print();
	while(y > 500) --y, Print();
	L(i, 1, 999) L(j, 1, 999) d[i > 500][j > 500] += vis[i][j];
	int c1 = 0, c2 = 0;
	L(i, 0, 1) L(j, 0, 1) if(d[i][j] < d[c1][c2]) c1 = i, c2 = j;
	c1 = (c1 == 0 ? 1 : -1), c2 = (c2 == 0 ? 1 : -1);
	L(i, 1, 499) {
		if(vis[x + c1][y + c2]) x += c1, Print(), y += c2, Print();
		else x += c1, y += c2, Print();
	}
	assert(0);
	return 0;
}