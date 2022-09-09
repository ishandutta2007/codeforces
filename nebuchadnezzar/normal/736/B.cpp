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
const double PI = atan2(0, -1);
const int MAXV = 5000;

int sieve[MAXV];
int d[MAXV];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    vector<int> primes;
    for (int i = 2; i < MAXV; ++i) {
        if (!sieve[i]) {
            primes.puba(i);
            for (int j = i * 2; j < MAXV; j += i) {
                sieve[j] = 1;
            }
        }
    }

    fill(d, d + MAXV, INF);
    d[0] = 0;

    for (int i = 1; i < MAXV; ++i) {
        for (int p : primes) {
            if (p > i) { 
                break;
            }
            d[i] = min(d[i], d[i - p] + 1);
        }
    }

    int n;
    scanf("%d", &n);

    int ans = INF;

    for (int i = 0; i < MAXV; ++i) {
        if (n - i < 2) {
            break;
        }
        bool flag = true;
        int tmp = n - i;
        for (int j = 2; j * j <= tmp; ++j) {
            if (tmp % j == 0) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            //cerr << i << " " << d[i] + 1 << endl;
            ans = min(ans, d[i] + 1);
        }
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}