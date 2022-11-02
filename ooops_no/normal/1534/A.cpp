#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define pb push_back
#define ld long double

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>> v(n, vector<char>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }
        vector<char> a{'R', 'W'};
        bool f = 0;
        for (int k = 0; k < 2; k++){
            bool x = 0;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if (v[i][j] != '.' && v[i][j] != a[(i + j) % 2]){
                        x = 1;
                    }
                }
            }
            if (x) {
                swap(a[0], a[1]);
                continue;
            }
            cout << "YES\n";
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    cout << a[(i + j) % 2];
                }
                cout << endl;
            }
            f = 1;
            break;
        }
        if (!f) cout << "NO\n";
    }
    return 0;
}