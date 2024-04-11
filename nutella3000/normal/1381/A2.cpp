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
        string a, b;
        cin >> n >> a >> b;
        vector<int> res;
        vector<int> temp;
        for(int i = 0;i < n;i++) {
            if (i % 2 == 0) temp.emplace_back(i / 2);
            else temp.emplace_back(n - i / 2 - 1);
        }
        int id = n;
        bool cnt = false;
        for(int i : temp) {
            id--;
            if ((a[i] == b[id]) ^ cnt) res.emplace_back(1);
            cnt = !cnt;
            res.emplace_back(id + 1);
        }

        cout << res.size() << endl;
        for(int i : res) cout << i << " ";
        cout << endl;
    }
}