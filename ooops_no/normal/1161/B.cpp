#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);
        v.pb({a, b});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++){
        if (n % i != 0) continue;
        vector<pair<int,int>> u;
        for (auto to : v){
            int a = (to.first + i) % n, b = (to.second + i) % n;
            if (a > b) swap(a, b);
            u.pb({a, b});
        }
        sort(u.begin(), u.end());
        if (v == u){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}