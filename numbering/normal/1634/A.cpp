#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int i;
        bool isPel = true;
        for(i=0;i<n;i++) {
            if(s[i]!=s[n-1-i]) isPel = false;
        }
        if(isPel || k == 0) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}