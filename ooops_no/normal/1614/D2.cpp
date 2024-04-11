#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

const int N = 2e7 + 10;
int cnt[N];
ll dp[N];
bool prime[N];
vector<int> all;

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
    for (int i = 0; i < N; i++) prime[i] = 1;
    for (int i = 2; i < N; i++){
        if (prime[i]){
            all.pb(i);
            if ((ll)i * i < N){
                for (int j = i * i; j < N; j += i){
                    prime[j] = 0;
                }
            }
        }
    }
    for (int i = 1; i < N; i++){
        for (int j = i + i; j < N; j += i){
            cnt[i] += cnt[j];
        }
    }
    ll ans = 0;
    for (int i = N - 1; i >= 1; i--){
        dp[i] = (ll)cnt[i] * i;
        for (int k = 0; k < all.size(); k++){
            int j = all[k] * i;
            if (j >= N) break;
            dp[i] = max(dp[i], dp[j] + (ll)i * (cnt[i] - cnt[j]));
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}