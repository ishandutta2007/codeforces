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

char buf[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);
    scanf("%s", buf);

    int l = -1, r = MAXN * 2;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int last = 0;
        bool flag = true;
        bool gflag = true;
        for (int i = 0; buf[i]; ++i) {
            if (buf[i] == '.' && flag) {
                ++last;
                continue;
            }
            if (buf[i] == '*') {
                flag = false;
                continue;
            }
            if (buf[i] == 'P') {
                //cerr << i << " " << last << endl;
                if (i - last > mid) {
                    gflag = false;
                    break;
                }
                int g = i;
                int lastp = -1;
                while (g + 1 < n && min((g + 1 - i) * 2 + i - last, (i - last) * 2 + g + 1 - i) <= mid) {
                    ++g;
                    if (buf[g] == 'P') {
                        lastp = g;
                    }
                }
                last = g + 1;
                if (lastp != -1) {
                    while (last < n && lastp + mid >= last) {
                        if (buf[last] == 'P') {
                            lastp = last;
                        }
                        ++last;
                    }
                }
                flag = true;
                i = last - 1;
            }
        }
        if (!gflag || !flag) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}