#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int res, ma;
vector<int> v;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int a, i = 0; i < n; i++) {
        cin >> a;
        res += a*m;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int ile = 0;
    int it = n-1;
    for (int a, i = 0; i < m; i++) {
        cin >> a;
        if (a < v[n-1]) {
            cout << -1;
            return 0;
        }

        if (a > v[n-1]) {
            ile++;
            if (ile == m) {
                it--;
                ile = 1;
            }

            if (it < 0) {
                cout << -1;
                return 0;
            }

            res += a-v[it];
        }
    }

    cout << res;
    return 0;
}