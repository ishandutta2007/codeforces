#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 333;
const int M = 2e6 + 7;
struct data {
	int x, y, c;
	data (int xx = 0, int yy = 0, int cc = 0) {
		x = xx, y = yy, c = cc;
	}
} ;
int n, m, q, a[N][N], f[N * N], de[M]; 
vector< data > Del[M], Add[M], fi[M];
bool used[N][N];
#define P(i, j) ((i) * m + (j) - m)
void init() {
	L(i, 1, n * m) f[i] = i;
	L(i, 1, n) L(j, 1, m) used[i][j] = 0;
}
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return false;
	f[x] = y;
	return true;
}
int ad(int x, int y) {
	int res = 0;
	if(used[x - 1][y]) res += merge(P(x - 1, y), P(x, y)); 
	if(used[x][y - 1]) res += merge(P(x, y - 1), P(x, y)); 
	if(used[x + 1][y]) res += merge(P(x + 1, y), P(x, y)); 
	if(used[x][y + 1]) res += merge(P(x, y + 1), P(x, y)); 
	used[x][y] = 1;
	return res;
}
void Ad(int l, int r, int val) {
//	cout << l << " to " << r << " : " << val << "\n";
	de[l] += val, de[r + 1] -= val;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	L(i, 1, q) {
		int x, y, c;
		cin >> x >> y >> c;
		Del[a[x][y]].push_back(data(x, y, i)), a[x][y] = c, Add[c].push_back(data(x, y, i));
	}
	L(i, 1, n) L(j, 1, m) Add[0].push_back(data(i, j, 0)), fi[a[i][j]].push_back(data(i, j));
	de[0] = n * m;
	L(i, 0, max(1000, 1999999 / (n * m) + 1)) {
		int Mid = (! ((int) Del[i].size()) ? q : Del[i][0].c - 1);
		
		init();
		for(data x : Add[i]) 
			Ad(x.c, Mid, -ad(x.x, x.y));
		
		init();
		for(data x : fi[i]) 
			Ad(Mid + 1, q, -ad(x.x, x.y));
		
		R(j, Del[i].size() - 1, 0) 
			Ad(Mid + 1, Del[i][j].c - 1, -ad(Del[i][j].x, Del[i][j].y));
	}
	L(i, 1, q) de[i] += de[i - 1];
	L(i, 1, q) cout << de[i] << "\n";
	return 0;
}