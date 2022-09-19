#include <bits/stdc++.h>

using namespace std;
int n, lo=0, hi=1e7, mid, ans=hi;
int ask(int a) {
    cout.flush() << "? " << a << "\n";
    int x;
    cin >> x;
    if (x) {
        ans=min(ans, a*x);
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (ask(mid)==1) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    for (int i=2; i<=n; i++) {
        ask(hi/i);
    }
    cout << "! " << ans << "\n";
    return 0;
}