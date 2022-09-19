#include <bits/stdc++.h>

using namespace std;
long long w, n, k, l1, l2, r1, r2, a, b, ans, s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> k >> l1 >> r1 >> l2 >> r2, a=max(l1, l2)-min(r1, r2), b=max(r1, r2)-min(l1, l2), ans=1e10;
        for (int i=1; i<=n; i++) {
            if (b*i>=k) ans=min(ans, i*a+k);
            else {
                s=k-b*i;
                ans=min(ans, i*(a+b)+2*s);
            }
        }
        if (ans<0) ans=0;
        cout << ans << "\n";
    }
    return 0;
}