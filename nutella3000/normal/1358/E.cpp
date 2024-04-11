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
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    cin >> n;
    vector<int> a((n + 3) / 2);
    int x, sum = 0;;
    for(int i = 1;i < (n + 3) / 2;i++) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> x;

    if (x > 0) {
        cout << (sum + (n / 2) * x > 0 ? n : -1);
        return 0;
    }

    vector<int> b((n + 3) / 2);
    for(int i = 1;i < (n + 3) / 2;i++) {
        b[i] = b[i - 1] + x - a[i];
    }
    for(int i = 1;i < (n + 3) / 2;i++) {
        b[i] = min(b[i], b[i - 1]);
    }

    for(int k = n - n / 2;k <= n;k++) {
        int s = sum + x * (k - (n + 1) / 2);
        int c = b[n - k];
        if (s + c > 0) {
            cout << k;
            return 0;
        }
    }
    cout << -1;
}