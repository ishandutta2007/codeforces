#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define pb push_back
#define ld long double

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
        vector<int> a(n);
        int mx = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        if (n == 1){
            cout << a[0] << endl;
            continue;
        }
        int sum = a[0] + a.back();
        for (int i = 0; i < n - 1; i++){
            sum += abs(a[i] - a[i + 1]);
        }
        if (a[0] > a[1]){
            sum -= a[0] - a[1];
            a[0] = a[1];
        }
        for (int i = 1; i < n - 1; i++){
            if (a[i] > a[i - 1] && a[i] > a[i + 1]){
                sum -= a[i] - max(a[i - 1], a[i + 1]);
                a[i] = max(a[i + 1], a[i - 1]);
            }
        }
        if (a[n - 1] > a[n - 2]){
            sum -= abs(a[n - 1] - a[n - 2]);
        }
        cout << sum << endl;
    }
    return 0;
}