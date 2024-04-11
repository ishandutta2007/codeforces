#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int now = 0, ans = 0;
    map<int,int> mp;
    mp[now] = 1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        now ^= min(a[i], (1 << k) - 1 - a[i]);
        mp[now]++;
    }
    for (auto to : mp){
        int val = to.second / 2;
        ans += val * (val - 1) / 2;
        val = (to.second + 1) / 2;
        ans += val * (val - 1) / 2;
    }
    cout << n * (n + 1) / 2 - ans << endl;
    return 0;
}