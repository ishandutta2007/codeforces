#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;

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
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0;i < n;i++) cin >> p[i];
        int Min = inf;
        int id_min = -1;
        bool good = false;
        vector<int> a(n + 1);
        for(int i = 0;i < n;i++) a[p[i]] = i;

        for(int i = 0;i < n;i++) {
            a[p[i]] = -1;

            bool bad = Min > p[i];
            int num = inf;
            for(int j = 1;j <= n;j++) {
                if (a[j] != -1) {
                    if (j > p[i]) bad = true;
                    num = a[j];
                    break;
                }
            }
            if (num == inf) bad = true;

            if (!bad) {
                cout << "YES" << endl;
                cout << id_min + 1 << " " << i + 1 << " " << num + 1 << endl;
                good = true;
                break;
            }
            if (Min > p[i]) {
                Min = p[i];
                id_min = i;
            }
        }
        if (!good) cout << "NO" << endl;
    }
}