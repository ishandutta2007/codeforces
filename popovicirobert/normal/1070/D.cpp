#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, x;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    ll s = 0, ans = 0;
    int t = 0;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(t == 0) {
            s += x;
            ans += s / k;
            s %= k;
        }
        else {
            if(s + x < k) {
                s = 0;
                ans++;
            }
            else {
                s += x;
                ans += s / k;
                s %= k;
            }
        }
        if(s > 0) {
            t++;
        }
        else {
            t = 0;
        }
    }
    cout << ans + (s + k - 1) / k;
    //cin.close();
    //cout.close();
    return 0;
}