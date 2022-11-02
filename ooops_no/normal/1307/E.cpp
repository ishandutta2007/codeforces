#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    vector<pair<int,int>> c(m), u, uu;
    vector<int> go(m + 1), go_rev(m + 1);
    for (int i = 0; i < n; i++){
        cin >> s[i];
        s[i]--;
    }
    for (int i = 0; i < m; i++){
        cin >> c[i].first >> c[i].second;
        c[i].first--;
    }
    c.pb({n, 1});
    m++;
    for (int i = 0; i < m; i++){
        int j = 0, need = c[i].second;
        while(j < n && need){
            if (s[j] == c[i].first) need--;
            j++;
        }
        go[i] = j - (need == 0);
        u.pb({go[i], i});

        j = n - 1, need = c[i].second;
        while(j >= 0 && need){
            if (s[j] == c[i].first) need--;
            j--;
        }
        go_rev[i] = j + (need == 0);
        uu.pb({go_rev[i], i});
    }
    sort(u.begin(), u.end());
    sort(uu.begin(), uu.end());
    int anss = 0, cntt = 0;
    for (int i = 0; i < u.size(); i++){
        int ind = u[i].second, last = -1;
        int ans = 0, cnt = 1;
        if (go[ind] == n && c[ind].first != n) continue;
        vector<bool> used(n + 1);
        vector<int> l(n + 1), r(n + 1);
        if (c[ind].first != n){
            used[c[ind].first] = 1;
            l[c[ind].first]++;
            ans++;
        }
        for (int j = i - 1; j >= 0; j--){
            int color = c[u[j].second].first;
            if (used[color] || go[u[j].second] == n) continue;
            l[color]++;
        }
        fill(used.begin(), used.end(), 0);
        last = -1;
        for (int j = 0; j < uu.size(); j++){
            int nw = uu[j].second;
            if (go_rev[nw] <= go[ind] || go[ind] == go[nw]) continue;
            int color = c[nw].first;
            r[color]++;
        }
        for (int i = 0; i <= n; i++){
            if (i == c[ind].first){
                cnt = (cnt * max(1ll, r[i])) % MOD;
                if (r[i] > 0) ans++;
                continue;
            }
            if (l[i] == 0){
                if (r[i] > 0){
                    ans++;
                    cnt = (cnt * r[i]) % MOD;
                }
            }
            else if (r[i] == 0){
                if (l[i] > 0){
                    ans++;
                    cnt = (cnt * l[i]) % MOD;
                }
            }
            else{
                int mn = min(l[i], r[i]), mx = max(l[i], r[i]);
                if (mn == mx && mn == 1){
                    cnt = (cnt * 2) % MOD;
                    ans++;
                }
                else{
                    cnt = (cnt * mn * max(1ll, mx - 1)) % MOD;
                    ans += 2;
                }
            }
        }
        if (ans > anss){
            anss = ans, cntt = cnt;
        }
        else if (ans == anss){
            cntt = (cntt + cnt) % MOD;
        }
    }
    cout << anss << ' ' << cntt << endl;
    return 0;
}