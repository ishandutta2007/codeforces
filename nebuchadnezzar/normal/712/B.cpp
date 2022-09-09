#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXL = 1e5 + 5;

char s[MAXL];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%s", s);

    int n = strlen(s);
    if (n & 1) {
        cout << "-1\n";
        return 0;
    }

    int x = 0, y = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            ++y;
        } else if (s[i] == 'D') {
            --y;
        } else if (s[i] == 'L') {
            --x;
        } else {
            ++x;
        }
    }

    cout << (abs(x) + abs(y)) / 2 << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}