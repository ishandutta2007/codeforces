#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        ll ans = (ll) (1 + n) * n / 2;
        for (ll j = 1; j <= n; j *= 2) {
            ans -= j * 2;
        }
        cout << ans << endl;
    }                

    return 0;
}