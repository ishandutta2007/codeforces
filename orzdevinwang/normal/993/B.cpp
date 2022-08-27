#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
using namespace std;
const int N = 2e3 + 7;
void Max(int &x, int y) { if(x < y) x = y;}
void Min(int &x, int y) { if(x > y) x = y;}
int n, m;
int a[N][2], b[N][2];
int f[N][N];
int can(int x, int y) {
	if(a[x][0] == a[x][1]) return 0;
	if(b[y][0] == b[y][1]) return 0;
	int cnt = 0, dd;
	L(i, 0, 1) L(j, 0, 1) cnt += (a[x][i] == b[y][j]), (a[x][i] == b[y][j]) && (dd = a[x][i]);
	if(cnt == 1) return dd;
	return 0;
}
bool case1() {
	int x = 0;
	L(i, 1, n) L(j, 1, m) if(can(i, j)) {
		if(x && x != can(i, j)) return 0;
		x = can(i, j);
	}
	if(x) {
		cout << x << endl;
		return 1;
	}
	return 0;
}
bool case2() {
	bool flag = 0;
	L(i, 1, n) {
		int x = 0;
		L(j, 1, m) if(can(i, j)) {
			if(x && x != can(i, j)) return 0;
			x = can(i, j);
		}
		if(x) flag = 1;
	}
	return flag;
}
bool case3() {
	bool flag = 0;
	L(j, 1, m) {
		int x = 0;
		L(i, 1, n) if(can(i, j)) {
			if(x && x != can(i, j)) return 0;
			x = can(i, j);
		}
		if(x) flag = 1;
	}
	return flag;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> a[i][0] >> a[i][1];
	L(i, 1, m) cin >> b[i][0] >> b[i][1];
	if(case1()) return 0;
	if(case2() && case3()) return cout << "0\n", 0;
	cout << "-1\n";
	return 0;
}