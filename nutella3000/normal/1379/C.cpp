#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
 
signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int t;
    cin >> t;
 
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pii> a(m);
        for(int i = 0;i < m;i++) cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end(), [](pii v1, pii v2) {return v1.first > v2.first;});
 
        vector<int> pref(m);
        for(int i = 0;i < m;i++) {
            pref[i] = a[i].first;
            if (i != 0) pref[i] += pref[i - 1];
        }
 
 
        int res = pref[min(n, m) - 1];
 
        for(int i = 0;i < m;i++) {
            //cout << i << endl;
            int l = -1;
            int r = m;
            while(r - l > 1) {
                int mid = (l + r) / 2;
                if (a[mid].first > a[i].second) l = mid;
                else r = mid;
            }
 
            //cout << l << endl;
            int q = 0;
            if (l >= 0) q = pref[l];
            if (l >= i) {
                if (n - l - 1 >= 0)  res = max(res, q + a[i].second * (n - l - 1));
            }else if (n - l - 2 >= 0) res = max(res, q + a[i].first + a[i].second * (n - l - 2));
        }
 
        cout << res << endl;
    }
}