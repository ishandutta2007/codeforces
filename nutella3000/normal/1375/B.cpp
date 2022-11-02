#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
const int inf = 1e9 + 7;
int dirx[]{1, 0};
int diry[]{0, 1};


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
        }

        bool bad = false;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                int cnt = 4;
                if (i == 0 || i == n - 1) cnt--;
                if (j == 0 || j == m - 1) cnt--;
                if (a[i][j] > cnt) bad = true;
            }
        }
        if (bad) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) {
                    int cnt = 4;
                if (i == 0 || i == n - 1) cnt--;
                if (j == 0 || j == m - 1) cnt--;
                    cout << cnt << " ";
                }
                cout << endl;
            }
        }
    }
}