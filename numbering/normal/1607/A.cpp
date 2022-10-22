#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[30];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int i;
        for(i=0;i<s1.length();i++) {
            A[s1[i]-'a'] = i;
        }
        int ans = 0;
        for(i=1;i<s2.length();i++) {
            ans += abs(A[s2[i]-'a']-A[s2[i-1]-'a']);
        }
        cout << ans << '\n';
    }
}