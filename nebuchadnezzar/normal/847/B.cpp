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
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }




int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);
    vector<vector<int>> ans;

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        int l = -1, r = szof(ans);

        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (ans[mid].back() >= num) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (r == szof(ans)) {
            ans.puba({});
        }
        ans[r].puba(num);
    }
    
    for (auto& v : ans) {
        for (int num : v) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}