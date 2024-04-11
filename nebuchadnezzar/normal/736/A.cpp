#include "bits/stdc++.h"
#define puba push_back
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

ll res[100];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    ll n;
    scanf("%lld", &n);

    res[0] = 1;
    res[1] = 2;

    for (int i = 2; i < 100; ++i) {
        res[i] = res[i - 1] + res[i - 2];
        if (res[i] > n) {
            cout << i - 1 << "\n";
            return 0;
        }
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}