#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cnt = 0, cnt1 = 0, ans = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') cnt++;
            if (s[i] == '[') cnt1++;
            if (s[i] == ')') {
                if (cnt != 0){
                    ans++;
                    cnt--;
                }
            }

            if (s[i] == ']'){
                if (cnt1 != 0){
                    ans++;
                    cnt1--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}