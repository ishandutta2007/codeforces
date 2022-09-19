#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, t[c], maxi, d, pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        maxi=1, d=0, pos=0;
        for (int i=2; i<=n; i++) {
            d=__gcd(d, abs(t[i]-t[i-1]));
            if (d>1) {
                maxi=max(maxi, i-pos);
            } else {
                d=0;
                pos=i;
                long long s=0;
                while (d!=1) {
                    s=d;
                    d=__gcd(d, abs(t[pos]-t[pos-1]));
                    pos--;
                }
                d=s;
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}