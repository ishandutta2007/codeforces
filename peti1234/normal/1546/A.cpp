#include <bits/stdc++.h>

using namespace std;
int w, n, sa, sb, dif, a[102], b[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sa=0, sb=0, dif=0;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            sa+=a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
            sb+=b[i];
            dif+=abs(a[i]-b[i]);
        }
        if (sa!=sb) {
            cout << -1 << "\n";
        } else {
            dif/=2;
            cout << dif << "\n";
            for (int l=1; l<=dif; l++) {
                for (int i=1; i<=n; i++) {
                    for (int j=1; j<=n; j++) {
                        if (a[i]>b[i] && a[j]<b[j]) {
                            cout << i << " " << j << "\n";
                            a[i]--, a[j]++;
                        }
                    }
                }
            }
        }
    }
    return 0;
}