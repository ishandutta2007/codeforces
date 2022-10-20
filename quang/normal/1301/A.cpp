#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        string a, b, c;
        cin >> a >> b >> c;
        int found = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == c[i] || b[i] == c[i]) continue;
            found = 1;
        }
        cout << (found ? "NO" : "YES") << '\n';
    }   
    return 0;
}