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
const int SZ1 = 60 * 201, SZ2 = 26 * 201, SZ3 = 201;

int d[SZ2][SZ3];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < SZ2; ++i) {
        for (int j = 0; j < SZ3; ++j) {
            d[i][j] = -INF;
        }
    }
    d[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        ll num;
        scanf("%lld", &num);
        int p2 = 0;
        while (num % 2 == 0) {
            p2++;
            num /= 2;
        }
        int p5 = 0;
        while (num % 5 == 0) {
            p5++;
            num /= 5;
        }

        
        //cerr << p2 << " " << p5 << endl;

        for (int x = SZ2 - 1; x >= 0; --x) {
            for (int y = k - 1; y >= 0; --y) {
                if (x + p5 < SZ2) {
                    d[x + p5][y + 1] = max(d[x + p5][y + 1], d[x][y] + p2);
                }
            }
        }

        /*
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                cerr << d[x][y] << " ";
            }
            cerr << endl;
        }
        cerr << endl;
        */
    }
    
    int ans = 0;
    for (int i = 0; i < SZ2; ++i) {
        ans = max(ans, min(i, d[i][k]));
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}