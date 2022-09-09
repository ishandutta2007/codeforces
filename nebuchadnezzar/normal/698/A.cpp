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
const int MAXN = 1e5 + 5;
const int INF = 1e9 + 8;

int n;
int d[3][MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < 3; ++j) {
            d[j][i] = INF;
        }
    }

    d[0][0] = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        //cerr << d[0][i + 1] << " " << d[1][i + 1] << " " << d[2][i + 1] << endl;
        int num;
        scanf("%d", &num);
        //cerr << num << endl;
        d[0][i + 1] = min(d[0][i], min(d[1][i], d[2][i])) + 1;
        if (num & 1) {
            d[1][i + 1] = min(d[0][i], d[2][i]);
        }
        if (num & 2) {
            d[2][i + 1] = min(d[0][i], d[1][i]);
        }
        //cerr << d[0][i + 1] << " " << d[1][i + 1] << " " << d[2][i + 1] << endl;
    }

    cout << min(d[0][n], min(d[1][n], d[2][n])) << "\n";

    return 0;
}