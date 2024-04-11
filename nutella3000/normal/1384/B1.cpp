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
        int n, k, l;
        cin >> n >> k >> l;
        vector<int> d(n + 1);
        d[0] = -inf;
        for(int i = 1;i <= n;i++) {
            cin >> d[i];
            d[i] -= l;
        }

        int id = 0;
        bool bad = false;
        while(id < n) {
            int num = k + 1;
            bool down = true;
            id++;
            while(d[id] + k > 0) {
                if (down) {
                    num--;
                    num = min(num, -d[id]);
                }else {
                    num++;
                    if (d[id] + num > 0) bad = true;
                }
                //cout << id << " " << num << endl;
                if (num < 0) bad = true;
                if (num == 0) down = false;
                
                id++;
                if (id == n + 1) break;

                if (bad) break;
            }
            if (bad) break;
        }

        if (bad) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}