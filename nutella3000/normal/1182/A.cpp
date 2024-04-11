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
    int n;
    cin >> n;
    if (n % 2 == 1) cout << 0;
    else{
        int ans = 1;
        ans *= (1 << (n / 2));
        cout << ans;
    }
}