#include <bits/stdc++.h>

using namespace std;
long long n, cnt, x, e, ans=1;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        cnt++;
        if (x==1) {
            if (!e) {
                e=1;
            } else {
                ans*=cnt;
            }
            cnt=0;
        }
    }
    if (!e) {
        ans=0;
    }
    cout << ans << "\n";
    return 0;
}