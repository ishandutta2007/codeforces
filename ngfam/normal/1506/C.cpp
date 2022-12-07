#include <bits/stdc++.h>

using namespace std;

int main() {

    int ntest; cin >> ntest;
    while(ntest--) {
        int ans = 0;
        string a, b; cin >> a >> b;
        for(int i = 0; i < a.size(); ++i) {
            for(int j = 0; j < b.size(); ++j) {
                int cur = 0;
                while(i + cur < a.size() && j + cur < b.size() && a[i+cur] == b[j+cur]) {
                    cur += 1;
                }
                ans = max(ans, cur);
            }
        }
        cout << a.size() + b.size() - ans - ans << endl;
    }

    return 0;
}