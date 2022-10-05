#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int ask(int a, int b, int c, int d) {
	if (a + b > c + d) {
		swap(a, c);
		swap(b, d);
	}
	cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << endl;
	fflush(stdout);
	int rtn;
	cin >> rtn;
	return rtn;
}

int n;
int ans[55][55], ans2[55][55];
int dp1[50][50][50][50], dp2[50][50][50][50];

int calc1(int a, int b, int c, int d) {
	if (a > c || b > d) return false;
	if (a < 0 || c >= n || b < 0 || d >= n) return false;
	if (ans[a][b] != ans[c][d]) return false;
	if (dp1[a][b][c][d] != -1) return dp1[a][b][c][d];
	if (c - a + d - b <= 1) {
		return dp1[a][b][c][d] = 1;
	}
	return dp1[a][b][c][d] = calc1(a + 1, b, c - 1, d) | calc1(a + 1, b, c, d - 1) | calc1(a, b + 1, c - 1, d) | calc1(a, b + 1, c, d - 1);
}
int calc2(int a, int b, int c, int d) {
	if (a > c || b > d) return false;
	if (a < 0 || c >= n || b < 0 || d >= n) return false;
	if (ans2[a][b] != ans2[c][d]) return false;
	if (dp2[a][b][c][d] != -1) return dp2[a][b][c][d];
	if (c - a + d - b <= 1) {
		return dp2[a][b][c][d] = 1;
	}
	return dp2[a][b][c][d] = calc2(a + 1, b, c - 1, d) | calc2(a + 1, b, c, d - 1) | calc2(a, b + 1, c - 1, d) | calc2(a, b + 1, c, d - 1);
}

void flip() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		if ((i + j) % 2 == 1)
			ans[i][j] ^= 1;
}

void end() {
	cout << "!" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << ans[i][j]; cout << endl;
	}
	cout.flush();
	exit(0);
}

void work(int a, int b, int c, int d) {
	ans[c][d] = ans[a][b] ^ ask(a, b, c, d) ^ 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) for (int l = 0; l < n; l++) {
		dp1[i][j][k][l] = dp2[i][j][k][l] = -1;
	}
	ans[0][0] = ans[0][1] = 1;
	work(0, 0, 0, 2);
	work(0, 1, 1, 2);
	work(0, 0, 1, 1);
	work(1, 2, 1, 0);
	work(0, 0, 2, 0);
	work(0, 1, 2, 1);
	work(0, 2, 2, 2);

	for (int i = 3; i < n; i++) {
		for (int j = 0; j < i; j++)
			work(i - 2, j, i, j);
		for (int k = 0; k < i; k++)
			work(k, i - 2, k, i);
		work(i - 1, i - 1, i, i);
	}
	if (OO) {
		cout << "ans\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << ans[i][j] << " "; cout << '\n';
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if ((i + j) & 1) ans2[i][j] = 1 ^ ans[i][j];
		else ans2[i][j] = ans[i][j];
	}
	for (int a = 0; a < n; a++) for (int b = 0; b < n; b++) for (int c = a; c < n; c++) for (int d = b; d < n; d++) {
		if (c - a + d - b >= 2 && calc1(a, b, c, d) != calc2(a, b, c, d)) {
			int res = ask(a, b, c, d);
			if (res == calc2(a, b, c, d)) flip();
			end();
		}
	}

}