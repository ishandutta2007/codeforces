#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;
bool x[11];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int n, m;
    cin >> n >> m;
    int y[n];
    for(int i = 0;i < n;i++) cin >> y[i];
    for(int i = 0;i < m;i++) {
        int v;
        cin >> v;
        x[v] = true;
    }
    for(int i = 0;i < n;i++) if (x[y[i]]) cout << y[i] << " ";
}