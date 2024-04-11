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

int x, y;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &x, &y);

    multiset<int> now;
    now.insert(y);
    now.insert(y);
    now.insert(y);
    int ans = 0;

    while (*now.begin() < x) {
        auto it = now.begin();
        now.erase(it);
        it = now.begin();
        int tmp = *it;
        ++it;
        tmp += *it;
        int val = min(tmp - 1, x);
        now.insert(val);

        ++ans;
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}