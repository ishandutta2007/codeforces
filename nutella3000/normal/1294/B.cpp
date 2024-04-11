#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)(a.size())
#define all(_v) _v.begin(), _v.end()
typedef long double ld;

const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pii> a(n);
        for(int i = 0;i < n;i++) 
            cin >> a[i].fi >> a[i].se;

        sort(all(a));

        bool good = true;
        for(int i = 1;i < n;i++) {
            if (a[i].se < a[i - 1].se) good = false;
        }

        if (!good) {
            cout << "NO" << endl;
        }else {
            cout << "YES" << endl;
            pii last;
            for(int i = 0;i < n;i++) {
                while(last.fi != a[i].fi) {
                    cout << "R";
                    last.fi++;
                }
                while(last.se != a[i].se) {
                    cout << "U";
                    last.se++; 
                }
            }

            cout << endl;
        }
    }
}