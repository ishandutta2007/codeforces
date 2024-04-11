#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

bool inter(pair<int,int> a, pair<int,int> b){
    int ans = (a.first <= b.first && b.first <= a.second) + (a.first <= b.second && b.second <= a.second);
    return (ans == 1);
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
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> u;
        vector<bool> used(2 * n);
        for (int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (x > y) swap(x, y);
            used[x] = used[y] = 1;
            u.pb({x, y});
        }
        vector<int> a;
        for (int i = 0; i < 2 * n; i++){
            if (!used[i]){
                a.pb(i);
            }
        }
        for (int i = 0; i < n - k; i++){
            u.pb({a[i], a[i + n - k]});
        }
        int ans = 0;
        for (int i = 0; i < u.size(); i++){
            for (int j = i + 1; j < u.size(); j++){
                ans += inter(u[i], u[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}