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
        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];

        bool sorted = true;
        bool eq = false;
        vector<int> b;
        for(int i = 0;i < n;i++) {
            if (a[i] == i + 1) eq = true;
            else {
                b.emplace_back(i);
                sorted = false;
            }
        }
        eq = false;
        if (b.size()) {
            int last = b[0] - 1;
            for(int i : b) {
                if (last != i - 1) eq = true;
                last = i;
            }
        }

        if (sorted) cout << 0 << endl;
        else if (!eq) cout << 1 << endl;
        else cout << 2 << endl;
    }    
}