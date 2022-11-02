#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

pair<int,int> cnt(vector<int> p){
    int a = 0, b = 0;
    for (int i = 1; i + 1 < p.size(); i++){
        if (p[i] > p[i - 1] && p[i] > p[i + 1]) a++;
        if (p[i] < p[i - 1] && p[i] < p[i + 1]) b++;
    }
    return {a, b};
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
        int n, a, b;
        cin >> n >> a >> b;
        if (a + b > n - 2 || abs(a - b) > 1){
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        if (a > b){
            ans.pb(1);
            int now = 2;
            for (int i = 0; i < min(a, b); i++){
                ans.pb(now + 1);
                ans.pb(now);
                now += 2;
            }
            for (int i = n; i >= now; i--){
                ans.pb(i);
            }
        }
        else if (a < b){
            ans.pb(n);
            int now = n - 1;
            for (int i = 0; i < min(a, b); i++){
                ans.pb(now - 1);
                ans.pb(now);
                now -= 2;
            }
            for (int i = 1; i <= now; i++){
                ans.pb(i);
            }
        }
        else{
            ans.pb(1);
            int now = 2;
            for (int i = 0; i < min(a, b); i++){
                ans.pb(now + 1);
                ans.pb(now);
                now += 2;
            }
            for (int i = now; i <= n; i++){
                ans.pb(i);
            }
        }
        assert(cnt(ans) == make_pair(a, b));
        for (auto to : ans){
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}