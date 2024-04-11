#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;
 
const int inf = 1e15;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    vector<pii> res;

    res.emplace_back(1, 2);
    res.emplace_back(1, 2);
    res.emplace_back(2, 2);
    res.emplace_back(2, 2 * sz(s) + 1);

    cout << res.size() << endl;
    for(pii i : res) {
        if (i.fi == 1) cout << "L ";
        else cout << "R ";
        cout << i.se << endl;
    }  
}