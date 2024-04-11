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

int n;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);
    vector<int> inp;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        inp.puba(num);
        if (num) {
            flag = true;
        }
    }

    if (!flag) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<pii> ans;
    int from = 0;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (inp[i]) {
            ++c;
        }
        if (c > 1) {
            ans.puba({from, i - 1});
            from = i;
            c = 1;
        }
    }

    ans.puba({from, n - 1});

    cout << szof(ans) << "\n";

    for (pii p : ans) {
        cout << p.ff + 1 << " " << p.ss + 1 << "\n";
    }
    

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}