#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

mt19937 rand_int(time(0));

ll n, k;

int main() {
    cin >> n >> k;
    ll l = 1, r = n;
    while (true) {
        while (r - l > 100) {
            ll m = l + r >> 1;
            cout << l << ' ' << m << endl;
            string op;
            cin >> op;
            if (op[0] == 'Y') r = m;
            else l = m + 1;
            l = max(1LL, l - k);
            r = min(n, r + k);
        }
        ll mod = r - l + 1;
        ll q = rand_int() % mod + l;
        cout << q << ' ' << q << endl;
        string op;
        cin >> op;
        if (op[0] == 'Y') return 0;
        l = max(1LL, l - k);
        r = min(n, r + k);
    }
}