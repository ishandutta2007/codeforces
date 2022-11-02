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
        if (s[0] == s[1]){
            s[1] = '#';
        }
        for (int i = 2; i < s.size(); i++){
            if (s[i - 2] == s[i]){
                s[i] = '#';
            }
            else if (s[i] == s[i - 1]){
                s[i] = '#';
            }
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '#') ans++;
        }
        cout << ans << endl;
    }
    return 0;
}