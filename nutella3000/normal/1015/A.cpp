#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;
bool used[max_n];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int n, m;
    cin >> n >> m;
    while(n--) {
        int v1, v2;
        cin >> v1 >> v2;
        while(v2 != v1 - 1) {
            used[v2--] = true;
        }
    }
    int cnt = 0;
    for(int i = 1;i <= m;i++) if (!used[i]) cnt++;
    cout << cnt << '\n';
    for(int i = 1;i <= m;i++) if (!used[i]) cout << i << " ";
}