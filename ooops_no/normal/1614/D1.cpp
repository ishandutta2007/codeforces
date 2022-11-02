#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

const int N = 5e6 + 10;
int cnt[N];
ll dp[N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i < N; i++){
        for (int j = i + i; j < N; j += i){
            cnt[i] += cnt[j];
        }
    }
    ll ans = 0;
    for (int i = N - 1; i >= 1; i--){
        dp[i] = (ll)cnt[i] * i;

        for (int j = i + i; j < N; j += i){
            dp[i] = max(dp[i], dp[j] + (ll)i * (ll)(cnt[i] - cnt[j]));
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}