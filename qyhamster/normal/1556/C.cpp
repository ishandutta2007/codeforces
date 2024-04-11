#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long a[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(i&1) continue;
        long long cnt = 0, mn = -1;
        for(int j = i+1; j < n; j++) {
            if((i+j)&1) {
                cnt -= a[j];
                if(cnt < -a[i]) {
                    ans += a[i] + mn + 1;
                    break;
                }
                if(cnt <= mn) ans += mn - cnt + 1;
                mn = min(mn, cnt);
            }
            else{
                cnt += a[j];
            }
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}