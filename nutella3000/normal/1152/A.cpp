#include <bits/stdc++.h>

using namespace std;
#define int long long
#define loop1(from, n) for(int i = from; i < n;i++)
#define loop2(from, n) for(int i = from;i >= n;i--)
const int inf = 1e9 + 7;
int32_t main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for(int i = 0;i < n;i++) {
        int next;
        cin >> next;
        if (next % 2 == 0) cnt2++;
        else cnt1++;
    }
    for(int i = 0;i < m;i++) {
        int next;
        cin >> next;
        if (next % 2 == 0) cnt4++;
        else cnt3++;
    }
    cout << min(cnt4, cnt1) + min(cnt2, cnt3);
}