#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

void solve(){
    int n, k;
    cin >> n >> k;
    n--;
    int now = 1, ans = 0;
    while(now < k && n > 0){
        n -= now;
        now *= 2;
        ans++;
    }
    cout << ans + (max(0ll, n) + k - 1) / k << endl;
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
        solve();
    }
    return 0;
}