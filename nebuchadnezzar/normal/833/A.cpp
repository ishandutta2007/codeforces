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

ll get(int a, int b) {
    return a * INFL + b;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    vector<ll> v;
    for (int i = 1; i * i < INF; ++i) {
        for (int j = 1; i * j * j < INF && i * i * j < INF; ++j) {
            v.puba(get(i * j * j, i * i * j));
            //v.puba(get(i * i * j, i * j * j));
        }
    }

    sort(bend(v));
    //v.resize(unique(bend(v)) - v.begin());

    cerr << szof(v) << endl;

    int t;
    scanf("%d", &t);
    vector<pair<ll, int>> inp;

    for (int i = 0; i < t; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        inp.puba({get(a, b), i});
    }
    
    sort(bend(inp));
    vector<bool> ans(t);
    
    int c = 0;
    for (auto p : v) {
        while (c < szof(inp) && inp[c].ff < p) {
            ++c;
        }
        while (c < szof(inp) && inp[c].ff == p) {
            ans[inp[c].ss] = 1;
            ++c;
        }
    }
    
    for (int i = 0; i < t; ++i) {
        if (ans[i]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}