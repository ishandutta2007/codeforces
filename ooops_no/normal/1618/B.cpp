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
        vector<string> s(n - 2);
        for (int i = 0; i < n - 2; i++){
            cin >> s[i];
        }
        for (int i = 0; i + 1 < s.size(); i++){
            if (s[i][1] != s[i + 1][0]){
                string t = "";
                t += s[i][1];
                t += s[i + 1][0];
                s.insert(s.begin() + i + 1, t);
                break;
            }
        }
        if (s.size() == n - 2){
            string t = "";
            t += s.back()[1];
            t += 'a';
            s.pb(t);
        }
        cout << s[0][0];
        for (int i = 0; i < n - 1; i++){
            cout << s[i][1];
        }
        cout << endl;
    }
    return 0;
}