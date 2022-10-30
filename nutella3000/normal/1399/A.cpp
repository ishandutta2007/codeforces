#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const double inf = 1e17 + 7;



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
        for(int i = 0;i < n;i++) cin >> a[i];

        int Min = inf;
        for(int i = 0;i < n;i++) Min = min(Min, a[i]);

        for(int i = 0;i < n;i++) a[i] -= Min;

        vector<bool> used(n);

        bool bad = false;
        int Max = 0;
        for(int i = 0;i < n;i++) {
            if (a[i] >= n) bad = true;
            else used[a[i]] = true;
            Max = max(Max, a[i]);
        }

        for(int i = 0;i <= min(n - 1, Max);i++) {
            if (!used[i]) bad = true;
        }
        if (bad) cout << "NO";
        else cout << "YES";
        cout << endl;
    }
}