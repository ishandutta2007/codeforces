#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 205;

int n;
char s[MAXN];
bool used[MAXN][MAXN][MAXN];

int rec(int a, int b, int c) {
 	if (used[a][b][c]) {
 	 	return 0;
 	}
 	used[a][b][c] = 1;
 	if (a && b) {
 	 	rec(a - 1, b - 1, c + 1);
 	}
 	if (a && c) {
 	 	rec(a - 1, b + 1, c - 1);
 	}
 	if (b && c) {
 	 	rec(a + 1, b - 1, c - 1);
 	}
 	if (a >= 2) {
 	 	rec(a - 1, b, c);
 	}
 	if (b >= 2) {
 	 	rec(a, b - 1, c);
 	}
 	if (c >= 2) {
 	 	rec(a, b, c - 1);
 	}
 	return 0;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);

	int r = 0, g = 0, b = 0;

	for (int i = 0; i < n; ++i) {
	 	if (s[i] == 'R') {
	 	 	++r;
	 	} else if (s[i] == 'G') {
	 	 	++g;
	 	} else {
	 	 	++b;
	 	}
	}

	rec(r, g, b);

	if (used[0][0][1]) {
	 	cout << "B";
	}
	if (used[0][1][0]) {
	 	cout << "G";
	}
	if (used[1][0][0]) {
	 	cout << "R";
	}

	cout << "\n";


	return 0;
}