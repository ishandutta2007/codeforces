#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
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
#define ld double

const int inf = 1e15;



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
        int sum = 0;
        for(int i = 1;i < n;i++)
            sum += a[n - 1] - a[i];

        int res = sum - a[0];
        if (res < 0) {
            res = (n - 1) - ((a[0] - sum) % (n - 1));
            if (res == n - 1) res = 0;
        }

        cout << res << endl;
    }
}