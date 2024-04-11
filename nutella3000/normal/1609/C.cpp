#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }

const int inf = 1e9 + 7;
const int N = 4e5 + 3, M = 1e6 + 3;
int n, e;
int a[N], dp0[N], dp1[N];
bool prime[M];


void run() {
    cin >> n >> e;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) a[i] = 0;
        else if (prime[a[i]]) a[i] = 1;
        else a[i] = 2;
    }
    fill(dp0, dp0 + n + e, 0);
    fill(dp1, dp1 + n + e, 0);

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < 2) {
            if (a[i] == 0) {
                dp0[i] = dp0[i + e] + 1;
                dp1[i] = dp1[i + e] + 1;
            } else
                dp1[i] = dp0[i + e] + 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += max(0ll, dp1[i] - max(1ll, dp0[i]));
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    fill(prime, prime + M, 1);
    for (int i = 2; i < M; ++i) {
        if (!prime[i]) continue;
        for (int j = i * i; j < M; j += i) {
            prime[j] = false;
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}