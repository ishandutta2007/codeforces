#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define ld long double

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), used(n + 1), b;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (a[i] <= n && !used[a[i]]){
                used[a[i]] = 1;
            }
            else{
                b.pb(a[i]);
            }
        }
        sort(b.begin(), b.end());
        int j = 0;
        for (int i = 1; i <= n; i++){
            if (used[i]) continue;
            if (i * 2 < b[j]){
                j++;
            }
            else{
                break;
            }
        }
        if (j != b.size()) cout << -1 << endl;
        else cout << b.size() << endl;
    }
    return 0;
}