#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 4e5;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    vector<int> one;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] == 1) {
            one.push_back(i);
        }
    }
    int ans = 0;
    int now = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] == 1) {
            one.pop_back();
            arr[i] = 0;
            continue;
        }
        if (arr[i] % 2 == 1) {
            arr[i] -= 3;
            ans++;
        }
        int k = arr[i] / 2;
        arr[i] = 0;
        while (!one.empty() && one.back() > i) {
            one.pop_back();
        }
        while (!one.empty() && k) {
            k--;
            ans++;
            arr[one.back()] = 0;
            one.pop_back();
        }
        while (k != 0 && now < n) {
            if (arr[now] >= k) {
                arr[now] -= k;
                ans += k;
                k = 0;
                break;
            }
            ans += arr[now];
            k -= arr[now];
            arr[now] = 0;
            now++;
        }
        ans += (k * 2) / 3;
        // cout << ans << endl;
    }
    cout << ans;
    return 0;
}