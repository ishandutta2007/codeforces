#include <bits/stdc++.h>

using namespace std;
const int c=2002;
long long n, tav1[c], tav2[c], mini=1e18, x, y;
long long xa, ya, xb, yb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> xa >> ya >> xb >> yb;
    for (int i=1; i<=n; i++) {
        cin >> x >> y;
        tav1[i]=(x-xa)*(x-xa)+(y-ya)*(y-ya);
        tav2[i]=(x-xb)*(x-xb)+(y-yb)*(y-yb);
    }
    for (int i=0; i<=n; i++) {
        long long a=tav1[i], b=0;
        for (int j=1; j<=n; j++) {
            if (tav1[j]>a) {
                b=max(b, tav2[j]);
            }
        }
        mini=min(mini, a+b);
    }
    cout << mini << "\n";
    return 0;
}