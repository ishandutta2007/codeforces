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
        vector<int> d(n);
        for (int i = 0; i < n; i++){
            cin >> d[i];
        }
        sort(d.begin(), d.end());
        int ans = d.back(), sum = 0;
        for (int i = 0; i < n; i++){
            ans -= (i) * d[i] - sum;
            sum += d[i];
        }
        cout << ans << endl;
    }
    return 0;
}