#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 998244353;

void solve() {
    int n; cin >> n;
    vector<vector<int>> m(n, vector<int> (n));
    range(i, n) range(j, n) cin >> m[i][j];
    vector<int> a(n);
    range(i, n) {
        int x = i;
        int y = (i + 1) % n;
        int z = (i + 2) % n;
        ll kek = 1ll * m[x][y] * m[x][z] / m[y][z];
        a[x] = sqrtl(kek);
        while(1ll * a[x] * a[x] < kek) a[x]++;
        while(1ll * a[x] * a[x] > kek) a[x]--;
        cout << a[x] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}