#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;
const int mod = 1e9 + 7;

int n;
vector<int> a;


void solve() {
    cin >> n;
    a.resize(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        a[i]--;
    }

    int res = 0;
    int suf = 0;

    for(int i = 0;i < n;i++) {
        res += a[i] + suf * (i == 0 ? a[i] : min(a[i], a[i - 1]));

        int num = a[i];
        if (i != 0) num = min(num, a[i - 1]);
        if (i != n - 1) num = min(num, a[i + 1]);

        suf = suf * num + (i == n - 1 ? a[i] : min(a[i], a[i + 1]));

        res %= mod;
        suf %= mod;
    }

    cout << res;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}