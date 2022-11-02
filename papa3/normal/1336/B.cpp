#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 5e18;
const int mod = 1e9 + 7;

#define kwa(a) ((a) * (a))

struct Algo {
    int n[3];
    vector<int> v[3];
    
    Algo() {
        for (int i = 0; i < 3; i++) {
            cin >> n[i];
        }
        for (int a, i = 0; i < 3; i++) {
            for (int j = 0; j < n[i]; j++) {
                cin >> a;
                v[i].push_back(a);
            }
        }
        for (int i = 0; i < 3; i++) {
            sort(ALL(v[i]));
        }
        
        int res = INF;
        vector<int> per = {0, 1, 2};
        do {
            res = min(res, algo(v[per[0]], v[per[1]], v[per[2]]));
        } while (next_permutation(ALL(per)));
        cout << res << "\n";
    }
    
    int algo(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
        int x = 0, y = 0;
        int res = INF;
        
        for (int i : a) {
            while (x + 1 < b.size() && i > b[x]) x++;
            while (y + 1 < c.size() && i >= c[y + 1]) y++;
            
            res = min(res, kwa(i - b[x]) + kwa(i - c[y]) + kwa(c[y] - b[x]));
        }
        
        return res;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        Algo p;
    }
    
    return 0;
}/*

*/