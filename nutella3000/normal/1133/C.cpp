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
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e16; 

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    cin >> n;
    map<int, int> a;
    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        a[v]++;
    }

    int res = 0;
    for(pii st : a) {
        int new_res = 0;
        for(int i = st.fi;i <= st.fi + 5;i++) {
            if (a.count(i)) new_res += a[i];
        }

        res = max(res, new_res);
    }
    cout << res;
}