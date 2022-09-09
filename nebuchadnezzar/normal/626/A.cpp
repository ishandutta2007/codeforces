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

int getdir(char c) {
 	if (c == 'U') {
 	 	return 0;
 	}
 	if (c == 'R') {
 	 	return 1;
 	}
 	if (c == 'D') {
 	 	return 2;
 	}
 	if (c == 'L') {
 	 	return 3;
 	}
 	assert(false);
}

int n;
int dirs[MAXN];
char s[MAXN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);

	for (int i = 0; i < n; ++i) {
	 	dirs[i] = getdir(s[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
	 	int x = 0;
	 	int y = 0;
	 	for (int j = i; j < n; ++j) {
	 	 	x += dy[dirs[j]];
	 	 	y += dx[dirs[j]];
	 	 	if (x == 0 && y == 0) {
	 	 	 	++ans;
	 	 	 	//cerr << i << " " << j << endl;
	 	 	}
	 	}
	}

	cout << ans << "\n";

	return 0;
}