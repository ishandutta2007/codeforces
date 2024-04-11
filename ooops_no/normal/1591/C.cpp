#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

vector<int> rm;

int solve(vector<int> x, int k){
    if (x.size() == 0) return 0;
    int n = x.size(), ans = 0;
    for (int i = 0; i < x.size(); i++){
        x[i] = abs(x[i]);
    }
    sort(x.begin(), x.end());
    rm.pb(x.back());
    if (n <= k){
        return x.back() * 2;
    }
    while(x.size() > 0){
        ans += x.back() * 2;
        int sz = min((int)x.size(), k);
        for (int j = 0; j < sz; j++) x.pop_back();
    }
    return ans;
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
        int n, k, ans = 0;
        cin >> n >> k;
        vector<int> x, xx;
        rm = vector<int>{0};
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            if (a > 0){
                x.pb(a);
            }
            else if (a < 0){
                xx.pb(a);
            }
        }
        int res = solve(x, k) + solve(xx, k) - *max_element(rm.begin(), rm.end());
        cout << res << endl;
    }
    return 0;
}