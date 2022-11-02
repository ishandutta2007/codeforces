#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

vector<int> po(19);

void solve(){
    int n, k, ans = 0;
    cin >> n >> k;
    k++;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = po[a[i]];
    }
    a.pb(po.back());
    for (int i = 0; i + 1 < a.size(); i++){
        int can = a[i + 1] / a[i] - 1;
        if (can >= k){
            ans += k * a[i];
            k = 0;
        }
        else{
            ans += can * a[i];
            k -= can;
        }
    }
    cout << ans << endl;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    po[0] = 1;
    for (int i = 1; i < po.size(); i++) po[i] = po[i - 1] * 10;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}