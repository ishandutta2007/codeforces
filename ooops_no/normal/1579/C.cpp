#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> v(n, vector<char>(m));
        vector<vector<bool>> used(n, vector<bool>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (v[i][j] == '*'){
                    int d = 1;
                    while(i - d >= 0 && j + d < m && j - d >= 0){
                        if (v[i - d][j + d] != '*' || v[i - d][j - d] != '*'){
                            break;
                        }
                        d++;
                    }
                    d--;
                    if (d >= k){
                        for (int f = 0; f <= d; f++){
                            used[i - f][j - f] = used[i - f][j + f] = 1;
                        }
                    }
                }
            }
        }
        bool x = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (v[i][j] == '*' && !used[i][j]){
                    x = 1;
                }
            }
        }
        cout << (!x ? "YES" : "NO") << endl;
    }
    return 0;
}