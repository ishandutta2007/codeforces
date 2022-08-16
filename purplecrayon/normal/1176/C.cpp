#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<int> cnt(6);
    int n; cin >> n;
    
    map<int, int> mp;
    mp[4] = 0;
    mp[8] = 1;
    mp[15] = 2;
    mp[16] = 3;
    mp[23] = 4;
    mp[42] = 5;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (mp[c] == 0) cnt[0]++;
        else {
            if (cnt[mp[c]-1]) cnt[mp[c]]++, cnt[mp[c]-1]--;
        }
    }
    cout << n-cnt[5]*6 << '\n';
}