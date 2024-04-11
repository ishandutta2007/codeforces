#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for(int i = 0;i < n;i++)
            cin >> a[i];

        int res = 0;
        for(int i = 0;i < n - 1;i++)
            if (a[i][m - 1] == 'R') res++;

        for(int i = 0;i < m - 1;i++)
            if (a[n - 1][i] == 'D') res++;

        cout << res << endl;
    }
}