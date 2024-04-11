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
typedef pair <int, int> pii;
const int MAXN = 505;

int n, m;
char s[MAXN];
int field[MAXN][MAXN];
int ssum[2][MAXN][MAXN];

int get(int from, int x1, int y1, int x2, int y2) {
 	return ssum[from][x2 + 1][y2 + 1] - ssum[from][x1][y2 + 1] - ssum[from][x2 + 1][y1] + ssum[from][x1][y1];
}

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
     	scanf("%s", s);
     	for (int j = 0; j < m; ++j) {
     	 	if (s[j] == '#') {
     	 	 	field[i][j] = 1;
     	 	}
     	}
    }

    for (int i = 0; i < n; ++i) {
     	for (int j = 0; j < m; ++j) {
     	 	if (i < n - 1 && !field[i][j] && !field[i + 1][j]) {
     	 	 	ssum[0][i + 1][j + 1] = 1;
     	 	}
     	 	if (j < m - 1 && !field[i][j] && !field[i][j + 1]) {
     	 	 	ssum[1][i + 1][j + 1] = 1;
     	 	}
     	}
    }

    for (int i = 0; i < 2; ++i) {
     	for (int j = 1; j < MAXN; ++j) {
     	 	for (int k = 1; k < MAXN; ++k) {
     	 	 	ssum[i][j][k] = ssum[i][j - 1][k] + ssum[i][j][k - 1] - ssum[i][j - 1][k - 1] + ssum[i][j][k];
     	 	}
     	}
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; ++i) {
     	int x1, y1, x2, y2;
     	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);     	
     	--x1; --y1; --x2; --y2;

		printf("%d\n", get(0, x1, y1, x2 - 1, y2) + get(1, x1, y1, x2, y2 - 1));
    }

    return 0;
}