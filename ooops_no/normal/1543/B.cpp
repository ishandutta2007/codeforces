#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

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
        vector<int> v(n), a(n);
        int sum = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
        }
        int need = sum / n;
        int cnt = sum - need * n;
        for (int i = 0; i < n; i++){
            a[i] = need;
            if (cnt){
                a[i]++;
                cnt--;
            }
        }
        sum = 0;
        int ans = 0;
        sort(a.begin(), a.end());
        for (int i = 0;i < n; i++){
            ans += (a[i] * (i) - sum);
            sum += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}