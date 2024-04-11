#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

LL gcd(LL x, LL y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    LL a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    LL base = 0;
    for (int i = 0; i + 1 < n; i++)
        base = gcd(base, a[i + 1] - a[i]);
    for (int i = 0; i < m; i++) {
        LL x;
        cin >> x;
        cout << gcd(a[0] + x, base) << ' ';
    }
    cout << '\n';
    return 0;
}