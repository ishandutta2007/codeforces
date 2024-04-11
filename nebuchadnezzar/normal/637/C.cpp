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
const int MAXN = 1005, MAXL = 10;

int n;
char s[MAXN][MAXL];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	scanf("%s", s[i]);
	}

	int ans = 6;

	for (int i = 0; i < n; ++i) {
	 	for (int j = i + 1; j < n; ++j) {
	 	 	int diff = 0;
	 	 	for (int k = 0; k < 6; ++k) {
	 	 	 	diff += (s[i][k] != s[j][k]);
	 	 	}
	 	 	ans = min(ans, (diff - 1) / 2);
	 	}
	}

	cout << ans << "\n";

	return 0;
}