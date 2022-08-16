#include <bits/stdc++.h>
using namespace std;

int frog(string s) {
    int c = 0, max = 1;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'L')
            c += 1;
        if (s[i] == 'R') {
            c = 0;
        }
        if (c + 1 > max)
            max = c + 1;
    }
    return max;
}

int main() {
    int t;
    cin >> t;
    
    vector<int> ans(t, 0);
    
    for (int cas = 0; cas < t; cas++) {
        string s;
        cin >> s;
        ans[cas] = frog(s);
    }
    
    for (int i = 0; i < t; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}