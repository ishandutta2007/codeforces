#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        if (s[0] == ')' || s[n - 1] == '('){
            cout << "No\n";
        }
        else{
            if (n % 2 == 1){
                cout << "No\n";
            }
            else{
                cout << "Yes\n";
            }
        }
    }
    return 0;
}