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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        map<char, int> ind;
        for (int i = 0; i < s.size(); i++){
            ind[s[i]] = i;
        }
        string t;
        cin >> t;
        int ans = 0;
        for (int i = 0; i + 1 < t.size(); i++){
            ans += abs(ind[t[i]] - ind[t[i + 1]]);
        }
        cout << ans << endl;
    }
    return 0;
}