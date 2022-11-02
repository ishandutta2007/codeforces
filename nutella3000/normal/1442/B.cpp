#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int mod = 998244353;

int binpow(int a, int b) {
    int res = 1;
    for(;b > 0;b /= 2, a = a * a % mod) 
        if (b & 1) res = res * a % mod;
    return res;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(k), pos(n + 1, -1);

        for(int i = 0;i < n;i++) 
            cin >> a[i];

        for(int i = 0;i < k;i++) {
            cin >> b[i];
            pos[b[i]] = i;
        }

        bool bad = false;

        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if (pos[a[i]] == -1) continue;
            int good = 0;
            if (i > 0 && pos[a[i - 1]] < pos[a[i]]) good++;
            if (i < n - 1 && pos[a[i + 1]] < pos[a[i]]) good++;

            cnt += good - 1;
            if (good == 0) bad = true;
        }

        if (bad) {
            cout << 0 << endl;
            continue;
        }

        cout << binpow(2, cnt) << endl;
    }
}