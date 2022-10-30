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
#define ld double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e9 + 7;
const int N = 305;

void run() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> x;
    for (int i = 0; i < n; ++i)
        a[i] -= x;

    vector<int> dp(n), b(n);
    for (int i = 0; i < n-2; ++i) {
        if (a[i]+a[i+1] >= 0 && a[i]+a[i+1]+a[i+2] >= 0) b[i] = 1;
    }
    int lst = 0;
    for (int i = 0; i < n; ++i) {
        if (i) dp[i] = dp[i-1];

        if (i >= 2 && !b[i-2]) lst = i-1;

        if (i == 0 || a[i-1]+a[i] < 0) chkmax(dp[i], 1 + (i >= 2 ? dp[i-2] : 0));
        else {
            chkmax(dp[i], i-lst+1 + (lst - 2 >= 0 ? dp[lst-2] : 0));
        }
    }

    cout << dp[n-1] << endl;   
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(5);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}