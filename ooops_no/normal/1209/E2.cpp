#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

bool cmp(vector<int> a, vector<int> b){
    int mx = *max_element(a.begin(), a.end()), mxx = *max_element(b.begin(), b.end());
    return mx > mxx;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[j][i];
        }
    }
    sort(a.begin(), a.end(), cmp);
    while(a.size() > n) a.pop_back();
    m = a.size();
    vector<int> ans(1 << n);
    for (int i = 0; i < m; i++){
        vector<int> anss(1 << n), mx(1 << n);
        for (int j = 0; j < (1 << n); j++){
            for (int k = 0; k < n; k++){
                int sum = 0;
                for (int f = k; f < k + n; f++){
                    if (j & (1 << (f - k))){
                        sum += a[i][f % n];
                    }
                }
                mx[j] = max(mx[j], sum);
            }
        }
        for (int j = 0; j < (1 << n); j++){
            int now = ((1 << n) - 1) - j;
            for (int q = now; q; q = (q - 1) & now){
                anss[q | j] = max(anss[q | j], ans[j] + mx[q]);
            }
        }
        for (int j = 0; j < (1 << n); j++){
            ans[j] = max(ans[j], anss[j]);
        }
    }
    cout << ans[(1 << n) - 1] << endl;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}