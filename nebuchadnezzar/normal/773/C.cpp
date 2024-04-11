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



int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    
    int n;
    scanf("%d", &n);

    vector<ll> inp;
    map<ll, int> have;
    for (int i = 0; i < n; ++i) {
        ll num;
        scanf("%lld", &num);
        inp.puba(num);
        have[num]++;
    }

    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        int cur = i;
        if (have[1] < cur) {
            continue;
        }
        int cnt = 0;
        ll val = 1;
        //cerr << "i: " << i << endl;
        while (cur) {
            int now = min(cur, have[val]);
            //cerr << val << " " << cur << endl;
            int rest = cur - now;
            int amount = lower_bound(bend(inp), val) - inp.begin() - cnt;

            cnt += min(amount, rest);
            cnt += now;

            cur = now;

            val *= 2;
        }

        if (cnt == n) {
            flag = true;
            cout << i << " ";
        }
    }

    if (!flag) {
        cout << "-1";
    }

    cout << "\n";
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}