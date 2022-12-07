#include <bits/stdc++.h>

using namespace std;

int main() {
    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        map<int, int> mp;
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            mx = max(mx, ++mp[x]);
        }
    
        cout << max(n%2, 2 * mx - n) << endl;
    }
    return 0;
}