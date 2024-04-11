#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll m;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%I64d", &m);

    ll l = 0, r = 1e18;

    while (r - l > 1) {
        ll mid = (r + l) / 2;
        ll now = 0;
        for (ll i = 2; ; ++i) {
            ll tmp = i * i * i;
            if (tmp > mid) {
                break;
            }
            now += mid / tmp;
        }

        if (now >= m) {
            r = mid;
        } else {
            l = mid;
        }
    }

    ll now = 0;
    for (ll i = 2; ; ++i) {
        ll tmp = i * i * i;
        if (tmp > r) {
            break;
        }
        now += r / tmp;
    }

    if (now != m) {
        cout << "-1\n";
        return 0;
    }

    cout << r << "\n";
    
    return 0;
}