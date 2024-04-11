#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);

int t;
map<ll, int> have;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        //cerr << i << endl;
        char c;
        scanf("\n%c", &c);
        //cerr << c << endl;
        if (c == '+') {
            ll num;
            scanf("%I64d", &num);
            ll mask = 0;
            ll now = 1;
            while (num) {
                mask += now * ((num % 10) & 1);
                num /= 10;
                now *= 2;
            }
            have[mask] += 1;
        } else if (c == '-') {
            ll num;
            scanf("%I64d", &num);
            ll mask = 0;
            ll now = 1;
            while (num) {
                mask += now * ((num % 10) & 1);
                num /= 10;
                now *= 2;
            }
            have[mask] -= 1;
        } else {
            ll num;
            scanf("%I64d", &num);
            ll tmp = 0;
            ll now = 1;
            while (num) {
                tmp += now * (num & 1);
                num /= 10;
                now *= 2;
            }
            cout << have[tmp] << "\n";
        }
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}