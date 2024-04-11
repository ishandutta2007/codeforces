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
char buf[100];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    int x = 10000;
    int y = 0;

    for (int i = 0; i < n; ++i) {
        //cerr << i << endl;
        int d;
        scanf("%d%s", &d, buf);
        if (buf[0] == 'N') {
            if (x + d > 10000) {
                cout << "NO\n";
                return 0;
            }
            x += d;
        } else if (buf[0] == 'S') { 
            if (x - d < -10000) {
                cout << "NO\n";
                return 0;
            }
            x -= d;
        } else {
            if (abs(x) == 10000) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    if (x != 10000) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}