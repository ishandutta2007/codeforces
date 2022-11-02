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

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0;i < n;i++)
       cin >> a[i];
    
    vector<vector<int>> cnt(n, vector<int>(m));

    int res = 0;

    for(int i = n - 1;i >= 0;i--) {
        for(int j = m - 1;j >= 0;j--) {
            if (i == n - 1 || j == m - 1 || j == 0 ||
                 a[i][j] != a[i + 1][j + 1] || a[i][j] != a[i + 1][j - 1] || a[i][j] != a[i + 1][j]) {
                cnt[i][j] = 1;
                res++;
                continue;
            }

            int sz = min(cnt[i + 1][j + 1], min(cnt[i + 1][j - 1], cnt[i + 1][j])) + 1;

            if (i + 2 * sz - 2 >= n || a[i + 2 * sz - 2][j] != a[i][j]) sz--;

            cnt[i][j] = sz;
            res += sz;
        }
    }    

    cout << res << endl;
}