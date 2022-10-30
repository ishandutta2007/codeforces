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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> pref;
        string temp;
        cin >> temp;
        for(int i = 0;i < n;i++) {
            a[i] = temp[i] - '0';
            a[i]--;
        }

        int res = 0;
        pref[0]++;
        int t = 0;
        for(int i = 0;i < n;i++) {
            t += a[i];
            //cout << t << " " << pref[t] << endl;
            res += pref[t];
            pref[t]++;
        }

        cout << res << endl;
    }
}