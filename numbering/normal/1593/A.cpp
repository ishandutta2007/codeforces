#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ma = max(max(a,b),c);
        int cnt = 0;
        if(a == ma) cnt++;
        if(b == ma) cnt++;
        if(c == ma) cnt++;
        if(cnt >= 2) cnt = 1;
        else cnt = 0;
        if(ma == a) cout << cnt << ' ';
        else cout << ma + 1 - a <<' ';
        if(ma == b) cout << cnt << ' ';
        else cout << ma + 1 - b << ' ';
        if(ma == c) cout << cnt << ' ';
        else cout << ma + 1 - c<< ' ';
        cout << '\n';
    }
}