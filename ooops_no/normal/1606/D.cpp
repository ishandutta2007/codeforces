#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back

mt19937 rnd(51);

const int INF = 1e9, N = 1e6 + 10;
int cnt[N];

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> mnl(n, vector<int>(m)), mxl(n, vector<int>(m)), mnr(n, vector<int>(m)), mxr(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            mnl[i][j] = min(a[i][j], (j > 0 ? mnl[i][j - 1] : INF));
            mxl[i][j] = max(a[i][j], (j > 0 ? mxl[i][j - 1] : -INF));
        }
    }
    for (int j = m - 1; j >= 0; j--){
        for (int i = 0; i < n; i++){
            mnr[i][j] = min(a[i][j], (j + 1 < m ? mnr[i][j + 1] : INF));
            mxr[i][j] = max(a[i][j], (j + 1 < m ? mxr[i][j + 1] : -INF));
        }
    }
    for (int j = 0; j < m - 1; j++){
        vector<int> a(n), b(n), sfa(n), sfb(n);
        iota(a.begin(), a.end(), 0);
        iota(b.begin(), b.end(), 0);
        sort(a.begin(), a.end(), [&] (int x, int y) {return mxl[x][j] > mxl[y][j];});
        sort(b.begin(), b.end(), [&] (int x, int y) {return mnr[x][j + 1] < mnr[y][j + 1];});
        vector<int> ans;
        int mn = INF, mx = -INF, bal = 0;
        for (int i = 0; i < n - 1; i++){
            mn = min(mn, mnl[a[i]][j]);
            mx = max(mx, mxr[b[i]][j + 1]);
            ans.pb(a[i]);
            if (cnt[a[i]] != 0) bal--;
            cnt[a[i]]++;
            if (cnt[a[i]] != 0) bal++;
            if (cnt[b[i]] != 0) bal--;
            cnt[b[i]]--;
            if (cnt[b[i]] != 0) bal++;
            if (mn > mxl[a[i + 1]][j] && mx < mnr[b[i + 1]][j + 1] && bal == 0){
                cout << "YES\n";
                vector<char> show(n, 'B');
                for (auto to : ans){
                    show[to] = 'R';
                }
                for (auto to : show) cout << to;
                cout << " " << j + 1 << "\n";
                return;
            }
        }
        cnt[a[n - 1]]++, cnt[b[n - 1]]--;
    }
    cout << "NO\n";
}

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
        solve();
    }
    return 0;
}