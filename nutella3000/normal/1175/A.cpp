#include <bits/stdc++.h>
using namespace std;

#define long long long
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        long n, k;
        cin >> n >> k;
        long ans = 0;
        while(n != 0) {
            if (n < k) {
                ans += n;
                break;
            }
            ans += n % k;
            ans++;
            n /= k;
        }
        cout << ans << '\n';
    }
}