#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ld long double
#define pb push_back

mt19937 rnd(51);

signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while(q--){
            int l, r;
            cin >> l >> r;
            l--, r--;
            bool x = 0;
            for (int i = 0; i < l; i++){
                if (s[i] == s[l]){
                    x = 1;
                }
            }
            for (int i = r + 1; i < n; i++){
                if (s[i] == s[r]){
                    x = 1;
                }
            }
            if (x){
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";
        }
    }
    return 0;
}