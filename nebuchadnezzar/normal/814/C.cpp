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
const int MAXN = 1505;

char buf[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);
    scanf("%s", buf);
    
    int q;
    scanf("%d", &q);
    vector<int> ans(q);
    vector<pii> reqs[26];

    for (int i = 0; i < q; ++i) {
        int m;
        char c;
        scanf("%d %c", &m, &c);
        reqs[c - 'a'].puba({m, i});
    }

    for (int i = 0; i < 26; ++i) {
        vector<int> res(n + 1);
        for (int from = 0; from < n; ++from) {
            int c = 0;
            for (int to = from; to < n; ++to) {
                c += (buf[to] != i + 'a');
                res[c] = max(res[c], to - from + 1);
            }
        }
        for (int j = 1; j <= n; ++j) {
            res[j] = max(res[j], res[j - 1]);
        }
        for (auto r : reqs[i]) {
            ans[r.ss] = res[r.ff];
        }
    }

    for (int num : ans) {
        cout << num << "\n";
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}