#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define ll long long

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
        if ((s.back() - '0') % 2 == 0){
            cout << 0 << endl;
        }
        else{
            if ((s[0] - '0') % 2 == 0){
                cout << 1 << endl;
            }
            else{
                bool ok = 0;
                for (auto to : s){
                    if ((to - '0') % 2 == 0) ok = 1;
                }
                cout << (ok ? 2 : -1) << endl;
            }
        }
    }
    return 0;
}