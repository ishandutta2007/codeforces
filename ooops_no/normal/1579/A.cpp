#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cnt = 0, cntt = 0;
        for (auto to : s){
            if (to == 'B') cnt++;
            else cntt++;
        }
        cout << (cnt == cntt ? "YES" : "NO") << endl;
    }
    return 0;
}