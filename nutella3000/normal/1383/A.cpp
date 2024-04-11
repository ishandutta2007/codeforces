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
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        int res = 0;
        while(true) {
            int Min = inf, Min1 = inf;
            int num = -1;
            for(int i = 0;i < n;i++) {
                if (b[i] != a[i]) {
                    if (a[i] < Min1) {
                        Min1 = a[i];
                        Min = inf;
                        Min = min(Min, (int)(b[i] - 'a'));
                    }
                    if (a[i] == Min1) Min = min(Min, (int)(b[i] - 'a'));;
                }
            }
            //cout << "Min " << Min << endl;
            if (Min == inf) break;
            for(int i = 0;i < n;i++) {
                if (b[i] != a[i] && a[i] == Min1) {
                    if (a[i] > b[i]) res = inf;
                    a[i] = Min + 'a';
                }
            }
            res++;
            if (res >= inf) break;
        }
        if (res >= inf) cout << -1 << endl;
        else cout << res << endl;
    }
}