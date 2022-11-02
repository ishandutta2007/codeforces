#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans[n + 1];
    bool f[n + 1];
    for(int i = 0;i < n + 1;i++) {
        ans[i] = 0;
        f[i] = false;
    }
    int cnt = 1;
    for(int i = 2;i <= n;i++) {
        if (ans[i] != 0) continue;
        ans[i] = cnt;
        for(int j = 2 * i;j <= n;j += i) {
            if (ans[j] == 0) ans[j] = cnt;
        }
        cnt++;
    }
    for(int i = 2;i <= n;i++) cout << ans[i] << " ";
}