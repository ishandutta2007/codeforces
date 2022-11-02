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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int Max = -inf, Min = inf;
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            Max = max(Max, a[i]);
            Min = min(Min, a[i]);
        }

        if (k % 2 == 1) {
            for(int i = 0;i < n;i++)
                cout << Max - a[i] << " ";
        }else {
            for(int i = 0;i < n;i++) 
                cout << a[i] - Min << " ";
        }
        cout << endl;
    }
}