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
        vector<int> a(n);
        int last = inf;
        bool good = false;
        for(int i = 0;i < n;i++) {
            int v;
            cin >> v;
            if (v >= last) good = true;
            last = v;
        }

        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}