#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> p(n); for (auto& it : p) cin >> it;
    while (m--) {
        int l, r, x; cin >> l >> r >> x, --l, --r, --x;
        int cnt=0;
        for (int i = l; i <= r; i++) cnt += p[i] < p[x];
        if (cnt != (x-l)) cout << "No\n";
        else cout << "Yes\n";
    }
}