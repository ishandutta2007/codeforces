#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);


int solve(int n, vector<int> a){
    int ans = n;
    if (n <= 2){
        ans = 0;
    }
    vector<int> u;
    map<int,int> cnt;
    for (int i = 0; i < a.size(); i++){
        u.pb(a[i]);
        cnt[a[i]]++;
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    for (int i = 0; i < u.size(); i++){
        ans = min(ans, n - cnt[u[i]]);
        int last = u[i], add = 0;
        while(1){
            int j = lower_bound(u.begin(), u.end(), 2 * last - u[i]) - u.begin();
            if (i == j) j++;
            if (j == u.size()) break;
            add++;
            last = u[j];
            ans = min(ans, n - cnt[u[i]] - add);
        }
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << solve(n, a) << endl;
    }
    return 0;
}