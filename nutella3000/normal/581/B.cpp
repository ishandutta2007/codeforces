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
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];
    vector<int> b(n);
    int res = 0;
    for(int i = n - 1;i >= 0;i--) {
        b[i] = res - a[i] + 1;
        res = max(res, a[i]);
    }

    for(int i : b)
        cout << max(0ll, i) << " ";
    
}