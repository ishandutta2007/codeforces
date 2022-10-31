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
        int n;
        cin >> n;
        string s;
        cin >> s;
        s += 'z' + 1;
        if (n > 1){
            if (s[0] == s[1]){
                cout << s[0] << s[0] << endl;
                continue;
            }
        }
        for (int i = 0; i < n; i++){
            cout << s[i];
            if (s[i] < s[i + 1]){
                string t = s.substr(0, i + 1);
                reverse(t.begin(), t.end());
                cout << t << endl;
                break;
            }
        }
    }
    return 0;
}