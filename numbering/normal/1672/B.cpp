#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[500005];
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
        int i = 0, j = 0;
        bool isPos = true;
        if(s[L-1]=='A') isPos = false;
        int sum = 0;
        for(i=0;i<L;i++) {
            sum += s[i]=='A'? 1 : -1;
            if(sum < 0) isPos = false;
        }
        cout << (isPos ? "YES\n" : "NO\n");
    }
}