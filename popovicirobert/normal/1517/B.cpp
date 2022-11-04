#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;





int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> vals;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                vals.push_back({x, i});
            }
        }
        sort(vals.begin(), vals.end());

        vector<vector<int>> sol(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            sol[vals[i].second][i] = vals[i].first;
        }
        for (int i = m; i < n * m; i++) {
            for (int j = 0; j < m; j++) {
                if (sol[vals[i].second][j] == 0) {
                    sol[vals[i].second][j] = vals[i].first;
                    break;
                }
            }   
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}