#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;
    string s; cin >> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        j--;
        
        vector<int> me;
        for (int k = i; k <= j; k++) me.push_back(a[k]);
        sort(me.rbegin(), me.rend());
        for (int x = 0; x < min(int(me.size()), k); x++) {
            ans += me[x];
        }
        
        i = j;
    }
    cout << ans << '\n';
}