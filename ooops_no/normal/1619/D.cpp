#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, mn = 1e18;
        cin >> m >> n;
        vector<vector<int>> p(n, vector<int>(m)), a(n, vector<int>(m));
        vector<vector<int>> need(m);
        vector<bool> good(m);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> p[j][i];
            }
        }
        int l = -1, r = 1e18;
        while(r - l > 1){
            int mid = (r + l) / 2, ok = 1;
            vector<int> cnt(m);
            for (int i = 0; i < n; i++){
                bool f = 0;
                for (int j = 0; j < m; j++){
                    if (p[i][j] >= mid){
                        cnt[j]++;
                        f = 1;
                    }
                }
                ok &= f;
            }
            if (*max_element(cnt.begin(), cnt.end()) > 1 && ok){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        cout << l << endl;
    }
    return 0;
}