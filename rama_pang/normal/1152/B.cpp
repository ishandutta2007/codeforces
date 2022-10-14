#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int x;
    cin >> x;
    vector<int> ans;
    int cnt = 0;
    while (__builtin_popcount(x) < 30) {
        bool put = false;
        for (int j = 29; j >= 0; j--) {
            if (!(x & (1 << j))) {
                ans.emplace_back(j + 1);
                x ^= ((1 << (j + 1)) - 1);
                cnt++;
                put = true;
                break;
            }
        }
        if (!put) {
            cnt++;
            ans.emplace_back(0);
        }
        if (__builtin_popcount(x) == 30) {
            break;
        }
        x++;
        cnt++;
    }

    cout << cnt << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}