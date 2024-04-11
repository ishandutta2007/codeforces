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

    int n;
    cin >> n;
    int res = 0;
    set<int> b;

    b.emplace(0);

    int sum = 0;

    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        sum += v;

        if (b.count(sum)) {
            res++;
            b.clear();
            b.emplace(0);
            sum = v;
        }
        b.emplace(sum);
        //cout << i << " " << sum << " " << sz(b) << endl;
    }

    cout << res << endl;
}