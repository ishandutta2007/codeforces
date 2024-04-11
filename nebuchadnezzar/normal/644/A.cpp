#include <bits/stdc++.h>
#define ff first
#define ss second
#define puba push_back
#define szof(_x) ((int) (_x).size())
#define bend(_x) (_x).begin(), (_x).end()
#define TASK_NAME ""           

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MAXN = 105;

int n, a, b;
int field[MAXN][MAXN];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	scanf("%d%d%d", &n, &a, &b);

	if (a * b < n) {
	 	cout << "-1\n";
	 	return 0;
	}

	int x = 0, y = 0, dy = 1;
	for (int i = 0; i < n; ++i) {
	 	field[x][y] = i + 1;
	 	y += dy;
	 	if (y < 0 || y >= b) {
	 	 	if (b & 1) {
	 	 	 	++x;
	 	 	 	y = 0;
	 	 	} else {
	 	 	 	++x;
	 	 	 	dy *= -1;
	 	 	 	y += dy;
	 	 	}
	 	}
	}

	for (int i = 0; i < a; ++i) {
	 	for (int j = 0; j < b; ++j) {
	 	 	cout << field[i][j] << " ";
	 	}
	 	cout << "\n";
	}
	return 0;
}