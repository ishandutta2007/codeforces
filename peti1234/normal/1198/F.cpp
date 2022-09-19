#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, t[c], p[c], ans[c], x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i], p[i]=i;
    }
    for (int i=1; i<=100; i++) {
        x=0, y=0;
        random_shuffle(p+1, p+n+1);
        for (int j=1; j<=n; j++) {
            int s=t[p[j]];
            if (!x || s%x) {
                ans[p[j]]=1;
                x=__gcd(x, s);
            } else {
                ans[p[j]]=2;
                y=__gcd(y, s);
            }
        }
        if (x==1 && y==1) {
            cout << "YES\n";
            for (int i=1; i<=n; i++) {
                cout << ans[i] << " ";
            }
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}