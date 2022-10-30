#include <bits/stdc++.h>
using namespace std;
const int sqr = 200;
const int n = 500001;
vector<int> a[sqr];
int b[n];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    for(int i = 0;i < sqr;i++) {
        for(int j = 0;j < i;j++) a[i].emplace_back(0);
    }
    int q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            b[x] += y;
            for(int j = 1;j < sqr;j++) {
                int new_x = x % j;
                a[j][new_x] += y;
            }
        }else{
            if (x < sqr) {
                cout << a[x][y] << '\n';
            }else{
                int ans = 0;
                for(int j = y + (y == 0 ? x : 0);j < n;j += x) ans += b[j];
                cout << ans << '\n';
            }
        }
    }
}