#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(s.length() == 1 || s[0] <= s[1]) {
            cout << s[0] << s[0] << endl;
            continue;
        }
        int x = 1;
        while(x+1 < s.length() && s[x+1] <= s[x]) x++;
        for(int i = 0; i <= x; i++) cout << s[i];
        for(int i = x; i >= 0; i--) cout << s[i];
        cout << endl;
    }
    return 0;
}