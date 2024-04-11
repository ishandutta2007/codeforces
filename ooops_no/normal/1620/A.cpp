#include<bits/stdc++.h>

using namespace std;

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
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'E') cnt++;
        }
        if (cnt + 1 != s.size()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}