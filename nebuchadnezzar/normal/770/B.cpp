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

int sum(ll num) {
    int ret = 0;
    while (num) {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

ll solve_stupid(ll n) {
    ll ans = 0;
    for (ll i = 0; i <= n; ++i) {
        if (sum(ans) <= sum(i)) {
            ans = i;
        }
    }
    return ans;
}

ll solve(ll n) {
    vector<int> arr;
    while (n) {
        arr.puba(n % 10);
        n /= 10;
    }

    ll ans = 0;

    for (int i = 0; i < szof(arr); ++i) {
        ll cur = 0;
        for (int j = szof(arr) - 1; j > i; --j) {
            cur = cur * 10 + arr[j];
        }
        cur = cur * 10 + arr[i] - 1;
        for (int j = 0; j < i; ++j) {
            cur = cur * 10 + 9;
        }
        if (sum(ans) < sum(cur) || (ans < cur && sum(ans) == sum(cur))) {
            ans = cur;
        }
    }
    ll cur = 0;
    for (int i = szof(arr) - 1; i >= 0; --i) {
        cur = cur * 10 + arr[i];
    }
    
    if (sum(ans) < sum(cur) || (ans < cur && sum(ans) == sum(cur))) {
        ans = cur;
    }
    
    return ans;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    /*
    for (int i = 1; i < 100000; ++i) {
        if (i % 10000 == 0) {
            cerr << i << endl;
        }
        //cerr << i << endl;
        ll ans1 = solve(i);
        ll ans2 = solve_stupid(i);
        //cerr << ans1 << " " << ans2 << endl;
        assert(ans1 == ans2);
    }

    cerr << "finished" << endl;
    */
    ll n;
    scanf("%lld", &n);

    
    cout << solve(n) << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}