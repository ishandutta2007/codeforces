#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n, m, k;
    cin >> n >> m >> k;
    bool good = false;

    for(int i = 2;i * i <= m;i++) {
        if (m % i == 0 && m / i >= k) good = true;
    }

    if (k == 1 && m != 1) good = true;

    if (n % 2 == 0 || !good) cout << "Marsel";
    else cout << "Timur";
}