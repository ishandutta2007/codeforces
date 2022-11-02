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
 
const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);

    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int res = 0;
        int num = 1;
        while(true) {
            if (num * (num + 1) / 2 > x) break;
            x -= num * (num + 1) / 2;
            res++;
            num = num * 2 + 1;
        }
        cout << res << endl;
    }
}