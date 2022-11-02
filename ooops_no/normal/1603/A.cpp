#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
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
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool ans = 1;
        for (int i = 0; i < n; i++){
            bool x = 0;
            for (int j = i; j >= 0; j--){
                if (a[i] % (j + 2) != 0){
                    x = 1;
                    break;
                }
            }
            if (!x) ans = 0;
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}