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
        string s;
        cin >> s;
        int L = s.length();
        if((s[L-1]-'0')%2==0) cout << "0\n";
        else if((s[0]-'0')%2==0) cout << "1\n";
        else {
            bool isE = false;
            for(int i = 0;i <L;i++) {
                if((s[i]-'0')%2==0) isE = true;
            }
            if(isE) cout << "2\n";
            else cout << "-1\n";
        }
    }
}