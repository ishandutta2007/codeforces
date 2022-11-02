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

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);

    int res = inf;

    for(int i = 3;i <= n;i++) {
        vector<int> b;
        for(int len = 2;len * len <= 2 * i;len++) {
            int st = i - len * (len - 1) / 2;
            if (st % len != 0 || st == 0) continue;
            st /= len;

            int num = pref[st + len - 1] ^ pref[st - 1];
            b.emplace_back(num);

            if (i == n && num == 0 && res == inf) res = len;
        }
        sort(all(b));
        b.emplace_back(inf);

        int last = -1;
        for(int j : b) {
            if (j == last) continue;
            if (j != ++last) {
                a[i] = last;
                break;
            }
        }

        pref[i] = pref[i - 1] ^ a[i];

        //cout << i << " " << a[i] << endl;
    }
    cout << endl;

    if (res == inf) cout << -1;
    else cout << res;
}