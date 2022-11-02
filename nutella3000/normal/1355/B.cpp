#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;
 
const int inf = 1e15;

pii f(int a) {
    int mn = inf, mx = -inf;
    while(a > 0) {
        mn = min(mn, a % 10);
        mx = max(mx, a % 10);
        a /= 10;
    }
    return mp(mn, mx);
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++)
            cin >> a[i];
        sort(all(a));

        int res = 0;
        int last = 0;
        for(int i = 0;i < n;i++) {
            if (a[i] <= i - last + 1) {
                res++;
                last = i + 1;
            }
        }
        cout << res << endl;
    }
}