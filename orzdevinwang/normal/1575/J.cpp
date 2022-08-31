#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7;
int n, m, k, a[N][N];
set < int > st[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	L(i, 1, n) 
		L(j, 1, m) {
			cin >> a[i][j];
			if(a[i][j] != 2) 
				st[j].insert(i);
		}
	while (k--) {
		int x = 1, y;
		cin >> y;
		while (1) {
			auto z = st[y].lower_bound(x);
			if(z == st[y].end()) break;
			x = *z;
			if(a[x][y] == 1) a[x][y] = 2, st[y].erase(x), y++;
			if(a[x][y] == 3) a[x][y] = 2, st[y].erase(x), y--;
		}
		cout << y << ' ';
	}
	return 0;
}