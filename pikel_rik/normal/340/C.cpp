#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(all(a));

    ll sum = 0, sleft = 0;

    for (int i = 1; i <= n; i++) {
        sleft += (i - 1) * (ll)a[i] - sum;
        sum += a[i];
    }

    ll p = sum + 2 * sleft;
    ll q = n;

    ll g = __gcd(p, q);
    p /= g; q /= g;

    cout << p << " " << q << "\n";
    return 0;
}