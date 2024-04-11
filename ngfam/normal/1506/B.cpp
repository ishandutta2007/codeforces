#include <bits/stdc++.h>

using namespace std;

int main() {

    int ntest; cin >> ntest;
    while(ntest--) {
        int n, k; string s;
        cin >> n >> k >> s;
        
        int start, finish;
        for(int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                start = i;    
                break;
            }
        }

        for(int i = n - 1; i >= 0; --i) {
            if (s[i] == '*') {
                finish = i;
                break;
            }
        }

        
        int ans = 1;
        while(start != finish) {
            start = min(start + k, n - 1);
            while(s[start] != '*') start--;
            ans += 1;

        }

        cout << ans << endl;

    }

    return 0;
}