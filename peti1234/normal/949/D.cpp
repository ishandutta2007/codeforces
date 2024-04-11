#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vii = vector<ii>;
const ll MOD = 1000000007;
const int INF = 1000000000;
const double PI = 3.14159265358979323846;
#define fi first
#define se second
#define pb push_back
#define sz(cont) static_cast<int>((cont).size())
#define all(cont) (cont).begin(),(cont).end()
#define REP(n) for(int i=0, _i=(n); i<_i; ++i)
#define FOR(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define DWN(i,n) for(int i=(n); i>=0; --i)
#define FORI(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
ll n, d, b;
ll t[100001];
ll k[100001];
ll l[100002];
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> d >> b;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        k[i] = k[i - 1] + t[i];
        l[n + 1 - i] = l[n + 2 - i] + t[n + 1 - i];
    }
    ll a, c;
    c = n / 2;
    a = n - c;
    ll x = 0, y = 0;
    for (int i = 1; i <= a; i++) {
        int p = min(i + i*d, n);
        //cout << i << " " << k[p] << " " << x << " " << (x + 1)*b << endl;
        if (k[p] >= (x + 1)*b) {
            x++;
        }
    }
    for (int i = n; i > a; i--) {
        ll p = max(1LL, i - (n - i + 1)*d);
        //cout << l[p] << " " << y + 1 << " " << b << endl;
        if (l[p] >= (y + 1)*b) {
            y++;
        }
    }
    for (int i = 1; i <= n; i++) {
        //cout << k[i] << " " << l[i] << endl;
    }
    cout << max(a - x, c - y) << endl;
}