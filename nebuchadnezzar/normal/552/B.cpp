#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;

ll n;
ll ans = 0;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    int c = 0;
    ll tmp = n;
    while (tmp) {
        ++c;
        tmp /= 10;
    }

    for (int i = 1; i < c; ++i) {
        ll prod = 9;
        for (int j = 0; j < i - 1; ++j) {
            prod *= 10;
        }
        ans += i * prod;
    }

    ll prod = 1;
    for (int j = 0; j < c - 1; ++j) {
        prod *= 10;
    }

    ans += (n - prod + 1) * c;

    cout << ans << endl;

    return 0;
}