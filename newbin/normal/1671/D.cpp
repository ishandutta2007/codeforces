#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;
int main(){
    int test;
    cin >> test;
    int c = 0;
    while (test--){
        int n, x;
        c++;
        cin >> n >> x;
        vector<int> a(n);
        for (int &t : a) cin >> t;
        int mnx = 0x3f3f3f3f, cnt = 2;
        ll ans = min((ll)abs(1 - a[0]) + x - 1, (ll)abs(1 - a[n - 1]) + x - 1);
        while (cnt--){
            mnx = abs(x - a[0]);
            for (int i = 1; i < n; i++){
                if (i ^ 1) mnx = min(mnx, abs(x - a[i - 1]) + abs(x - a[i - 2]) - abs(a[i - 1] - a[i - 2]));
                ans = min(min(ans, (ll)abs(1 - a[i - 1]) + abs(1 - a[i]) + mnx - abs(a[i] - a[i - 1])), (ll)x - 1 + abs(x - a[i - 1]) + abs(1 - a[i]) - abs(a[i] - a[i - 1]));
            }
            if(n > 1) mnx = min(mnx, abs(x - a[n - 1]) + abs(x - a[n - 2]) - abs(a[n - 1] - a[n - 2]));
            ans = min(min(ans, (ll)abs(1 - a[n - 1]) + mnx), (ll)abs(x - a[n - 1]) + x - 1);
            reverse(all(a));
        }
        for (int i = 1; i < n; i++) ans += abs(a[i] - a[i - 1]);
        cout << ans << "\n";
    }
    return 0;
}