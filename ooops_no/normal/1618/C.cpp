#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> check;
        int g = 0;
        for (int i = 0; i < n; i += 2){
            g = gcd(g, a[i]);
        }
        check.pb(g);
        g = 0;
        for (int i = 1; i < n; i += 2){
            g = gcd(g, a[i]);
        }
        check.pb(g);
        int ans = 0;
        for (auto to : check){
            bool f = 1;
            for (int i = 0; i + 1 < n; i++){
                if (a[i] % to == 0 && a[i + 1] % to == 0){
                    f = 0;
                }
                if (a[i] % to != 0 && a[i + 1] % to != 0){
                    f = 0;
                }
            }
            if (f){
                ans = to;
            }
        }
        cout << ans << endl;
    }
    return 0;
}