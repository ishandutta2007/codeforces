#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5 + 10;
vector<int> now(N);
int go[30][N];

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    fill(now.begin(), now.end(), n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mx = n;
    for (int i = n - 1; i >= 0; i--){
        for (int j = 2; j <= sqrt(a[i]); j++){
            if (a[i] % j == 0){
                mx = min(mx, now[j]);
                mx = min(mx, now[a[i] / j]);
                now[a[i] / j] = i;
                now[j] = i;
            }
        }
        if (a[i] != 1) {
            mx = min(mx, now[a[i]]);
            now[a[i]] = i;
        }
        go[0][i] = mx - 1;
    }
    for (int i = 1; i < 30; i++){
        for (int j = 0; j < n; j++){
            if (go[i - 1][j] < n - 1){
                go[i][j] = go[i - 1][go[i - 1][j] + 1];
            }
            else go[i][j] = n;
        }
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 0;
        for (int i = 29; i >= 0; i--){
            if (l >= n) break;
            if (go[i][l] <= r){
                l = go[i][l] + 1;
                ans += (1 << i);
            }
        }
        cout << ans + (l <= r) << endl;
    }
    return 0;
}