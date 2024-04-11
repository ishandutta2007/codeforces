#include <bits/stdc++.h>
#define int long long
using namespace std;
int sq(int n) {
    int s = 0, e = 3*1e9;
    while(s+1<e) {
        int mid = (s+e)/2;
        if(mid*mid>n) e = mid;
        else s = mid;
    }
    return s;
}
int calc(int n) {
    if(n<=4) return n;
    int s = sq(n);
    int ans = 3 * (s-1);
    if(n>=s*s) ans++;
    if(n>=s*s+s) ans++;
    if(n>=s*s+2*s) ans++;
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l-1) <<'\n';
    }
}