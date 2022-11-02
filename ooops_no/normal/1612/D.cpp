#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

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
        int a, b, x;
        cin >> a >> b >> x;
        bool f = 0;
        while(1){
            auto [u, v] = make_pair(a, b);
            if (u < x && v < x) break;
            if (u == x || v == x){
                f = 1;
                break;
            }
            if (u > v) swap(u, v);
            if (u == 0) break;
            if (x >= v % u && x <= v && abs(x - v) % u == 0){
                f = 1;
                break;
            }
            a = u, b = v % u;
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}