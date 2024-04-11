#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    
    int ans = 0;
    cin >> n >> k;

    for (int i = 0, last = -1, cnt = 0; i < n; ++i) {
        int c;
        cin >> c;

        if (c == last) {
            cnt = 1;
        } else {
            cnt++;
            last = c;
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}