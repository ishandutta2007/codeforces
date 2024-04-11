#include <bits/stdc++.h>

using namespace std;
long long w, n, x, ans, cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        ans=1, cnt=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            if (x==0) ans*=2;
            if (x==1) cnt++;
        }
        cout << ans*cnt << "\n";
    }
    return 0;
}