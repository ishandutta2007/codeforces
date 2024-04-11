#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

using namespace std;
const int inf = 2e9;

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    int group[n];
    for(int i = 0;i < n;i++) group[i] = 0;

    for(int bit = 30;bit >= 0;bit--) {
        unordered_set<int> next;
        for(int i = 0;i < n;i++) {
            if ((a[i] & (1 << bit)) == 0) next.emplace(group[i] << 1);
            else next.emplace((group[i] << 1) + 1);
        }
        for(int i = 0;i < n;i++) {
            int q = ((a[i] & (1 << bit)) == 0 ? 0 : 1);
            int w = (group[i] << 1) + q;
            if (next.find(w ^ 1) != next.end()) group[i] = (w ^ 1);
            else group[i] = w;
        }
    }
    int min = inf;
    int x = inf;
    for(int i = 0;i < n;i++) {
        if ((group[i] ^ a[i]) < min) {
            min = (group[i] ^ a[i]);
            x = group[i];
        }
    }
    cout << (min);
}