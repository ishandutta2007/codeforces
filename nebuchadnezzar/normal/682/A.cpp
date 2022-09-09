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

int n, m;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int rest = 5 - i % 5;
        int l = -1, r = 1e7;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (mid * 5 + rest > m) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans += r;
    }

    cout << ans << "\n";

    return 0;
}