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
const int MAXT = 105, MAXK = 1005, SZ = MAXT * MAXK * 2;
const ll MOD = 1e9 + 7;

int a, b, k, t;
ll d[MAXT][SZ * 2];
ll *arr[MAXT];
ll mem[MAXK * 4];
ll *numof = mem + MAXK * 2;
ll mem2[SZ * 2];
ll *pref = mem2 + SZ;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d%d%d", &a, &b, &k, &t);

    for (int i = 0; i < MAXT; ++i) {
        arr[i] = d[i] + SZ;
    }

    for (int i = 0; i <= 2 * k; ++i) {
        int l = i - k, r = i + k;
        l = max(l, -k);
        r = min(r, k);
        numof[i] = numof[-i] = r >= l ? r - l + 1 : 0;
    }

    arr[0][0] = 1;
    for (int i = 0; i < t; ++i) {
        int pos = -SZ + MAXK + MAXK + 5;
        ll val = 0;
        for (int j = -2 * k; j <= 2 * k; ++j) {
            val += (val + (ll) numof[j] * arr[i][pos + j]) % MOD;
        }

        for (int j = -SZ; j < SZ; ++j) {
            pref[j] = arr[i][j];
        }

        for (int j = -SZ + 1; j < SZ; ++j) {
            pref[j] = (pref[j - 1] + pref[j]) % MOD;
        }

        while (pos <= SZ - MAXK - MAXK) {
            arr[i + 1][pos] = val;
            val = (val - (pref[pos] - pref[pos - 2 * k - 1])) % MOD;
            if (val < 0) {
                val += MOD;
            }
            val = (val + (pref[pos + 2 * k + 1] - pref[pos])) % MOD; 
            ++pos;
        }
    }

    /*
    for (int i = 0; i <= t; ++i) {
        for (int j = -k * t; j <= k * t; ++j) {
            cerr << arr[i][j] << " ";
        }
        cerr << endl;
    }*/                                         

    ll ans = 0;
    for (int i = b - a + 1; i < SZ; ++i) {
        ans = (ans + arr[t][i]) % MOD;
    }

    cout << ans << "\n";
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}