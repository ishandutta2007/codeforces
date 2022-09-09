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

int n, k;
map<int, vector<int>> have;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        have[num % k].puba(num / k);
    }

    if (szof(have) > 1) {
        cout << "-1\n";
        return 0;
    }

    auto& v = have.begin() -> ss;

    sort(bend(v));

    ll ans = 0;
    for (int num : v) {
        ans += num - v.front();
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}