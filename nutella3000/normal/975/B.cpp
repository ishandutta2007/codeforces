#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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

    int n = 14;
    vector<int> a(n);
    ll res = 0;
    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++) {
        //cout << i << endl;

        ll new_res = 0;
        int num = a[i] / n;
        int cnt = a[i] % n;

        vector<int> b(n);
        for(int j = 0;j < n;j++) b[j] = a[j];

        b[i] = 0;

        int v = (i + 1) % n;

        for(int j = 0;j < cnt;j++) {
            b[v] += num + 1;
            v = (v + 1) % n;
        }

        for(int j = 0;j < n - cnt;j++) {
            b[v] += num;
            v = (v + 1) % n;
        }

        for(int j = 0;j < n;j++) 
            new_res += (b[j] % 2 == 0 ? b[j] : 0);

        res = max(res, new_res);

    }

    cout << res << endl;
}