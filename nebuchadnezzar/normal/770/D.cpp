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
const double PI = atan2(0, -1);
const int MAXN = 1005;

int n;
char buf[MAXN];
char res[MAXN][MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);
    scanf("%s", buf);

    int bal = 0;
    int h = 0;
    for (int i = 0; i < n; ++i) {
        if (buf[i] == '[') {
            ++bal;
        } else {
            --bal;
        }
        h = max(h, bal);
    }

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            res[i][j] = ' ';
        }
    }

    int pos = 0;
    int from = 0, to = 2 * h;
    for (int i = 0; i < n; ++i) {
        if (buf[i] == '[') {
            for (int j = from; j <= to; ++j) {
                res[j][pos] = '|';
            }
            res[from][pos] = res[to][pos] = '+';
            res[from][pos + 1] = res[to][pos + 1] = '-';
            pos++;
            from++;
            to--;
        } else {
            from--;
            to++;
            if (buf[i - 1] == '[') {
                pos += 3;
            }
            for (int j = from; j <= to; ++j) {
                res[j][pos] = '|';
            }
            res[from][pos] = res[to][pos] = '+';
            res[from][pos - 1] = res[to][pos - 1] = '-';
            pos++;
        }
    }

    for (int i = 0; i < h * 2 + 1; ++i) {
        int last = -1;
        for (int j = MAXN - 1; j >= 0; --j) {
            if (res[i][j] != ' ') {
                last = j;
                break;
            }
        }
        for (int j = 0; j <= last; ++j) {
            cout << res[i][j];
        }
        cout << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}