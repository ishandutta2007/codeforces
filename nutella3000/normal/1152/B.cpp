#include <bits/stdc++.h>

using namespace std;
#define int long long
#define loop1(from, n) for(int i = from; i < n;i++)
#define loop2(from, n) for(int i = from;i >= n;i--)
const int inf = 1e9 + 7;

int log(int a) {
    int ans = 0;
    int u = 1;
    while (u <= a) {
        u *= 2;
        ans++;
    }
    return ans - 1;
}

int32_t main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;
    vector<int> ans;
    int cnt = 0;
    while (__builtin_popcount(x) != log(x) + 1) {
        int i = log(x);
        ans.emplace_back(i + 1);
        x = (x ^ ((1 << (i + 1)) - 1));
        cnt++;
        if (__builtin_popcount(x) != log(x) + 1) {
            cnt++;
            x++;
        }
    }
    cout << cnt << '\n';
    for (int i : ans) cout << i << " ";
}