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

const int MAXN = 1e5 + 5;
int d[MAXN];
int from[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    memset(d, -1, sizeof d);
    
    int n;
    scanf("%d", &n);
    if (!n) {
        cout << "a\n";
        return 0;
    }
    vector<int> all;
    for (int i = 1; i * (i - 1) / 2 <= n; ++i) {
        all.puba(i * (i - 1) / 2);
    }
    
    memset(d, 127, sizeof d);
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < szof(all); ++j) {
            int num = all[j];
            if (i + num <= n) {
                if (d[i + num] > d[i] + 1) {
                    d[i + num] = d[i] + 1;
                    from[i + num] = j + 1;
                }
            }
        }
    }
    

    int cur = n;
    char c = 'a';
    while (cur) {
        for (int i = 0; i < from[cur]; ++i) {
            cout << c;
        }
        c++;
        cur -= from[cur] * (from[cur] - 1) / 2;
    }
    cout << "\n";
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}