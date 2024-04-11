#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define pb push_back
#define ld long double

const int MOD = 1e9 + 7;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<bool> used(n);
        vector<int> ind(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            ind[a[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
        int ans = 1;
        for (int i = 0; i < n; i++){
            if (!used[a[i]]){
                int now = i;
                while(!used[a[now]]){
                    used[a[now]] = 1;
                    now = ind[b[now]];
                }
                ans *= 2;
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }
    return 0;
}