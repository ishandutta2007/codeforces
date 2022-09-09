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
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);

int n, a, b;
    
bool check(int w1, int h1, int w2, int h2) {
    if (w1 > a || h1 > b) {
        return false;
    }
    int rest_w = a - w1;
    int rest_h = b - h1;
    if (rest_w >= w2 && b >= h2) {
        return true;
    }
    if (a >= w2 && rest_h >= h2) {
        return true;
    }
    return false;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%d%d%d", &n, &a, &b);

    vector<pii> inp;
    for (int i = 0; i < n; ++i) {
        int c, d;
        scanf("%d%d", &c, &d);
        inp.puba({c, d});
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int w1 = inp[i].ff;
        int h1 = inp[i].ss;
        for (int q = 0; q < 2; ++q) {
            for (int j = i + 1; j < n; ++j) {
                int w2 = inp[j].ff;
                int h2 = inp[j].ss;
                for (int q2 = 0; q2 < 2; ++q2) {
                    if (check(w1, h1, w2, h2)) {
                        ans = max(ans, w1 * h1 + w2 * h2);
                    }

                    swap(w2, h2);
                }
            }
            swap(w1, h1);
        }
    }
    
    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}