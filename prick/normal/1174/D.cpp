#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 1 << 18;

char used[maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> pref;
    for (int i = 0; i < (1 << n); ++i) {
        if (used[i]) continue;
        pref.push_back(i);
        used[i] = true;
        used[i ^ x] = true;
    }
    
    cout << sz(pref) - 1 << '\n';
    for (int i = 1; i < sz(pref); ++i) {
        cout << (pref[i] ^ pref[i - 1]) << ' ';
    }
}