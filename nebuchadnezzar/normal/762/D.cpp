#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 7;
const double PI = atan2(0, -1);
const int MAXN = 1e5 + 5;

int n;
int field[3][MAXN];
ll sfield[MAXN];
ll res[3][MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &field[i][j]);
            sfield[j] += field[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= n; ++j) {
            res[i][j] = -INFL;
        }
    }

    res[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        vector<ll> tmp(3);
        for (int j = 0; j < 3; ++j) {
            tmp[j] = res[j][i] + field[j][i];
        }

        vector<ll> tmp2(3);
        tmp2[0] = tmp[0];
        for (int j = 1; j < 3; ++j) {
            tmp2[j] = max(tmp2[j - 1] + field[j][i], tmp[j]);
        }
        for (int j = 0; j < 3; ++j) {
            res[j][i + 1] = max(res[j][i + 1], tmp2[j]);
        }
        tmp2[2] = tmp[2];
        for (int j = 1; j >= 0; --j) {
            tmp2[j] = max(tmp2[j + 1] + field[j][i], tmp[j]);
        }
        for (int j = 0; j < 3; ++j) {
            res[j][i + 1] = max(res[j][i + 1], tmp2[j]);
        }
        if (i >= 1) {
            res[2][i + 1] = max(res[2][i + 1], res[0][i - 1] + sfield[i - 1] + sfield[i]);
            res[0][i + 1] = max(res[0][i + 1], res[2][i - 1] + sfield[i - 1] + sfield[i]);
        }
    }

    /*
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= n; ++j) {
            cerr << res[i][j] << " ";
        }
        cerr << endl;
    }*/

    cout << res[2][n] << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}