#include <bits/stdc++.h>

using namespace std;

bool viz[1000001];

int main() {
    int k, i, x;
    cin >> k;
    int mx = 0;
    for(i = 1; i <= k; i++) {
        cin >> x;
        viz[x] = 1;
        mx = max(mx, x);
    }
    int cnt = k;
    i = 1;
    while(cnt < 25) {
        while(viz[i] == 1)
            i++;
        viz[i] = 1;
        cnt++;
        i++;
    }
    int ans = 0;
    for(i = mx; i > 0; i--)
        ans += (viz[i] == 0);
    cout << ans;
    return 0;
}