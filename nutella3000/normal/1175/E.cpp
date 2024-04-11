#include <bits/stdc++.h>
using namespace std;

#define long long long
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    pair<int,int> line[n];
    for(int i = 0;i < n;i++) {
        int l, r;
        cin >> l >> r;
        line[i] = {l, r};
    }
    sort(line, line + n);
    int log = 20;
    int N = 600000;
    int h[log][N];
    int id = 0;
    int max_r = 0;
    for(int i = 0;i < N;i++) {
        while(id < n && line[id].first <= i) {
            max_r = max(max_r, line[id].second);
            id++;
        }
        h[0][i] = max_r;
    }
    for(int i = 1;i < log;i++) {
        for(int j = 0;j < N;j++) {
            h[i][j] = h[i - 1][h[i - 1][j]];
        }
    }
    for(int i = 0;i < m;i++) {
        int ans = 0;
        int v, r;
        cin >> v >> r;
        int k = log - 1;
        while(k >= 0) {
            if (h[k][v] < r) {
                ans += (1 << k);
                v = h[k][v];
            }
            k--;
        }
        if (h[0][v] >= r) ans++;
        else ans = -1;
        cout << ans << '\n';
    }
}