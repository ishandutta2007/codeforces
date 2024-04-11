#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

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
        string s;
        cin >> s;
        int n = s.size();
        if (n % 2 == 1){
            cout << "NO\n";
        }
        else{
            if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}