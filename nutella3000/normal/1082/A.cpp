#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        int n,x,y,d;
        cin >> n >> x >> y >> d;
        int ans = 1000000001;
        if ((y - x) % d == 0) {
            ans = abs(y - x) / d;
        }
        if (y % d == 1) {
           ans = min((x - 1 + d - 1) / d + (y - 1) / d,ans);
        }
        if (n % d == y % d) {
        ans = min((n - x + d - 1) / d + (n - y) / d,ans);
        }
        if (ans == 1000000001) {
            cout << -1 << "\n";
        }else cout << ans << "\n";
    }
}