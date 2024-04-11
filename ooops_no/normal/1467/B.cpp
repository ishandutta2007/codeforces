#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long
#define ld long double

mt19937 rnd(51);

int ans = 1e18;

void solve(vector<int> a){
    int anss = 0;
    int n = a.size();
    for (int i = 1; i < n - 1; i++){
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) anss++;
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) anss++;
    }
    ans = min(ans, anss);
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ans = 1e18;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        if (n <= 2){
            cout << 0 << endl;
            continue;
        }
        solve(v);
        int st = ans;
        int f = v[0];
        v[0] = v[1];
        solve(v);
        v[0] = f;

        f = v[n - 1];
        v[n - 1] = v[n - 2];
        solve(v);
        v[n - 1] = f;

        vector<int> used(n);
        for (int i = 1; i < n - 1; i++){
            if (v[i] > v[i - 1] && v[i] > v[i + 1]) used[i] = 1;
            if (v[i] < v[i - 1] && v[i] < v[i + 1]) used[i] = 1;
        }
        for (int i = 1; i < n - 1; i++){
            int now = st, lol = st;
            now -= used[i] + used[i + 1] + used[i - 1];
            if (i > 1){
                if (v[i - 1] > v[i - 2] && v[i - 1] > v[i + 1]) now++;
                if (v[i - 1] < v[i - 2] && v[i - 1] < v[i + 1]) now++;
            }
            ans = min(ans, now);
            lol -= used[i] + used[i - 1] + used[i + 1];
            if (i + 2 < n){
                if (v[i + 1] > v[i + 2] && v[i + 1] > v[i - 1]) lol++;
                if (v[i + 1] < v[i + 2] && v[i + 1] < v[i - 1]) lol++;
            }
            ans = min(ans, lol);
        }
        cout << ans << endl;
    }
    return 0;
}