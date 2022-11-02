#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)(a.size())
#define all(_v) _v.begin(), _v.end()
typedef long double ld;

const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            cin >> a[i][j];
    }

    int res = 0;
    for(int j = 0;j < m;j++) {
        map<int, int> cnt;
        for(int i = 0;i < n;i++) {
            if ((a[i][j] - 1) % m != j || a[i][j] > n * m) continue;
            int num = (a[i][j] - 1) / m;
            int temp = (i - num + n) % n;
            cnt[temp]++;
        }

        int new_res = inf;
        for(int i = 0;i < n;i++) {
            new_res = min(new_res, i + n - cnt[i]);
        }
        res += new_res;
    }
    cout << res;
}