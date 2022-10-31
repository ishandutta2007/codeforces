#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

ld dist(pair<int,int> a, pair<int,int> b){
    return sqrt((ld)(a.first - b.first) * (a.first - b.first) + (ld)(a.second - b.second) * (a.second - b.second));
}

int check(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    ld ab = dist(a, b), bc = dist(b, c), ac = dist(a, c);
    ld p = (ab + bc + ac) / 2;
    return (int)((sqrt(p * (p - ab)) * sqrt((p - bc) * (p - ac))) * 2 + 0.5);
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
        int w, h;
        cin >> w >> h;
        vector<vector<int>> a;
        vector<int> b, c, d, e;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++){
            int x;
            cin >> x;
            a.pb({x, 0, 0});
            b.pb(x);
        }
        cin >> k;
        for (int i = 0; i < k; i++){
            int x;
            cin >> x;
            a.pb({x, h, 1});
            c.pb(x);
        }
        cin >> k;
        for (int i = 0; i < k; i++){
            int y;
            cin >> y;
            a.pb({0, y, 2});
            d.pb(y);
        }
        cin >> k;
        for (int i = 0; i < k; i++){
            int y;
            cin >> y;
            a.pb({w, y, 3});
            e.pb(y);
        }
        int ans = 0;
        for (auto to : a){
            if (to[2] != 0){
                ans = max(ans, check({b[0], 0}, {b.back(), 0}, {to[0], to[1]}));
            }
            if (to[2] != 1){
                ans = max(ans, check({c[0], h}, {c.back(), h}, {to[0], to[1]}));
            }
            if (to[2] != 2){
                ans = max(ans, check({0, d[0]}, {0, d.back()}, {to[0], to[1]}));
            }
            if (to[2] != 3){
                ans = max(ans, check({w, e[0]}, {w, e.back()}, {to[2], to[1]}));
            }
        }
        cout << ans << endl;
    }
    return 0;
}