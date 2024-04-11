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
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, ans = 1e18;
        cin >> n;
        string s;
        cin >> s;
        for (char i = 'a'; i <= 'z'; i++){
            int l = 0, r = n - 1, cnt = 0;
            while(l < r){
                if (s[l] == s[r]){
                    l++, r--;
                    continue;
                }
                if (s[l] == i){
                    l++, cnt++;
                }
                else if (s[r] == i){
                    r--, cnt++;
                }
                else{
                    cnt = 1e18;
                    break;
                }
            }
            ans = min(ans, cnt);
        }
        cout << (ans == 1e18 ? -1 : ans) << endl;
    }
    return 0;
}