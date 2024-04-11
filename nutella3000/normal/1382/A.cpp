#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 1e5 + 1;


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
        set<int> a, b;
            int v;
        for(int i = 0;i < n;i++) {
            cin >> v;
            a.emplace(v);
        }
        for(int i = 0;i < m;i++) {
            cin >> v;
            b.emplace(v);
        }

        bool goood = false;
        for(int i : a) {
            if (b.count(i)) {
                cout << "YES" << endl << 1 << " " << i << endl;
                goood = true;
                break;
            }
        }
        if (!goood) cout << "NO" << endl;
    }
}