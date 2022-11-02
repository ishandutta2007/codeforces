#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef double ld;
 
const int inf = 1e16; 
const int eps = 1e-6;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    cin >> n;
    int res = 0;
    int temp = 0;

    vector<int> a(n), b(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];
    for(int i = 0;i < n;i++) 
        cin >> b[i];

    map<pii, int> c;
    for(int i = 0;i < n;i++) {
        if (a[i] == 0 && b[i] != 0) continue;
        if (a[i] == 0 && b[i] == 0) {
            temp++;
            continue;
        }
        if (a[i] < 0) {
            a[i] = -a[i];
            b[i] = -b[i];
        }
        if (a[i] != 0) {
            int q = gcd(a[i], b[i]);
            a[i] /= q;
            b[i] /= q;
        }

        c[{a[i], b[i]}]++;
        res = max(res, c[{a[i], b[i]}]);
    }
    cout << res + temp;
}