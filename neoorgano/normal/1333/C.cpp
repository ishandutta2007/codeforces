#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
int arr[MAXN];
int pref[MAXN];
map<int, int> mp;

main() {
    int n;
    cin >> n;
    mp[0] = -1;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
        mp[pref[i + 1]] = -1;
    }
    int lst = -1;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        lst = max(lst, mp[pref[i]]);
        ans += i - lst - 1;
        mp[pref[i]] = i;
    }
    cout << ans;
    return 0;
}