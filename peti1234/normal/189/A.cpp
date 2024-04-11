#include <bits/stdc++.h>

using namespace std;
int n, a, b, c, ans;
int main()
{
    cin >> n >> a >> b >> c;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            int s=i*a+j*b;
            if (s<=n && (n-s)%c==0) {
                ans=max(ans, i+j+(n-s)/c);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}