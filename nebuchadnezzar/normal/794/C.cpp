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
const int MAXN = 3e5 + 5;

char buf[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%s", buf);

    string s = buf;

    int n = szof(s);

    scanf("%s", buf);

    string t = buf;

    sort(bend(s));
    sort(bend(t));
    reverse(bend(t));

    string res(n, '?');
    int c1 = 0, c2 = 0;
    int c3 = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (s[c1] < t[c2]) {
                res[c3++] = s[c1++];
            } else {
                int who = 0;
                if ((n - i) % 2 == 0) {
                    who = 1;
                }
                while (c3 < n) {
                    res[c3++] = who ? t[c2++] : s[c1++];
                    who ^= 1;
                }
            }
        } else {
            if (t[c2] > s[c1]) {
                res[c3++] = t[c2++];
            } else {
                int who = 1;
                if ((n - i) % 2 == 0) {
                    who = 0;
                }
                while (c3 < n) {
                    res[c3++] = who ? t[c2++] : s[c1++];
                    who ^= 1;
                }
            }
        }
    }
    
    cout << res << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}