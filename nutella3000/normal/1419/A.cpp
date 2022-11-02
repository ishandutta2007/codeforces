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
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool good = false;
        if (n % 2 == 1) {
            for(int i = 0;i < n;i += 2)
                if ((s[i] - '0') % 2 == 1) good = true;
        }else {
            good = true;
            for(int i = 1;i < n;i += 2) {
                if ((s[i] - '0') % 2 == 0) good = false;
            }
        }

        cout << (good ? 1 : 2) << endl;
    }
}