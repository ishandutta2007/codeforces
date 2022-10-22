#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        reverse(s.begin(),s.end());
        int ans = INF;
        int pt1 = 0;
        int pt2 = 0;
        while(pt1 < s.length() && s[pt1] != '0') pt1++;
        pt2 = pt1 + 1;
        while(pt2 < s.length() &&(s[pt2] != '0'&&s[pt2] != '5')) pt2++;
        if(pt2 < s.length()) ans = min(ans, pt2 - 1);
        pt1 = pt2 = 0;
        while(pt1 < s.length() && s[pt1] != '5') pt1++;
        pt2 = pt1 + 1;
        while(pt2 < s.length() &&(s[pt2] != '2'&&s[pt2] != '7')) pt2++;
        if(pt2 < s.length()) ans = min(ans, pt2 - 1);
        cout << ans << '\n';
    }
}