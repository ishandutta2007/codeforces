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

    int n, s;
    cin >> n >> s;
    if (s >= 2 * n) {
        cout << "YES" << endl;
        for(int i = 0;i < n - 1;i++)
            cout << 2 << " ";

        cout << s - (n - 1) * 2 << endl << 1;
    }else {
        cout << "NO";
    }
}