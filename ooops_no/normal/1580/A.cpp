#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int INF = 1e18;

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
        vector<vector<int>> a(n, vector<int>(m)), pr(n, vector<int>(m));
        vector<vector<int>> mn(m, vector<int>(m, INF));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                char c;
                cin >> c;
                a[i][j] = c - '0';
                pr[i][j] = a[i][j] + (j > 0 ? pr[i][j - 1] : 0);
            }
        }
        int anss = 1e18;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int jj = j; jj < m; jj++){
                    if (jj - j + 1 >= 4){
                        if (i > 0) mn[j][jj] += (a[i - 1][j] ^ 1) + (a[i - 1][jj] ^ 1) + (pr[i - 1][jj - 1] - pr[i - 1][j]);
                        if (i - 4 >= 0){
                            int add = 0;
                            for (int f = i - 3; f < i; f++){
                                add += (a[f][j] ^ 1) + (a[f][jj] ^ 1) + (pr[f][jj - 1] - pr[f][j]);
                            }
                            mn[j][jj] = min(mn[j][jj], (jj - j - 1) - (pr[i - 4][jj - 1] - pr[i - 4][j]) + add);
                        }
                        anss = min(anss, mn[j][jj] + (jj - j - 1) - (pr[i][jj - 1] - pr[i][j]));
                    }
                }
            }
        }
        cout << anss << endl;
    }
    return 0;
}