#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back

mt19937 rnd(51);

const int N = 1010;
int st[N][N][10][10], lg[N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++){
        lg[1 << i] = i;
    }
    for (int i = 1; i < N; i++){
        lg[i] = max(lg[i], lg[i - 1]);
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0; j--){
            if (a[i][j] == 0){
                continue;
            }
            dp[i][j] = min((j + 1 < m) * dp[i][j + 1], (i + 1 < n) * dp[i + 1][j]);
            int val = dp[i][j];
            dp[i][j] += a[i + val][j + val];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            st[i][j][0][0] = dp[i][j];
        }
    }
    for (int a = 0; a < 10; a++){
        for (int b = 0; b < 10; b++){
            if (a + b == 0) continue;
            for (int i = 0; i + (1 << a) <= n; i++){
                for (int j = 0; j + (1 << b) <= m; j++){
                    if (!a){
                        st[i][j][a][b] = max(st[i][j][a][b - 1], st[i][j + (1 << (b - 1))][a][b - 1]);
                    }
                    else{
                        st[i][j][a][b] = max(st[i][j][a - 1][b], st[i + (1 << (a - 1))][j][a - 1][b]);
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        int l = 0, r = min(y2 - y1, x2 - x1) + 1;
        while(r - l > 1){
            int mid = (r + l) / 2;
            int x = x2 - mid + 1, y = y2 - mid + 1;
            int a = lg[x - x1 - 1], b = lg[y - y1 - 1];
            if (max({st[x1][y1][a][b], st[x - (1 << a)][y1][a][b], st[x1][y - (1 << b)][a][b], st[x - (1 << a)][y - (1 << b)][a][b]}) >= mid){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        cout << l << '\n';
    }
    return 0;
}