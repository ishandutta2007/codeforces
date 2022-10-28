#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> op;
    if (n <= 32){
        for (int i = 3; i < n; i++) op.emplace_back(i, n);
        int c=n;
        while (c > 1){
            op.emplace_back(n, 2);
            c = (c+1)/2;
        }
    } else {
        for (int i = 3; i < n; i++) if (i != 8) op.emplace_back(i, n);
        int c=n;
        while (c > 1){
            op.emplace_back(n, 8);
            c = (c+7)/8;
        }
        c = 8;
        while (c > 1){
            op.emplace_back(8, 2);
            c /= 2;
        }
    }
    cout << op.size() << '\n';
    for (auto& it : op) cout << it.first << ' ' << it.second << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}