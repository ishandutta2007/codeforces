#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    int p[n];
    int a[n];
    for(int i = 0;i < n;i++) cin >> p[i];
    for(int i = 0;i < n;i++) cin >> a[i];
    int c[k];
    for(int i = 0;i < k;i++) cin >> c[i];
    int ans = 0;
    for(int u = 0;u < k;u++) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == a[c[u] - 1]) mx = max(mx,p[i]);
        }
        if (mx != p[c[u] - 1]) ans++;
    }
    cout << ans;
}