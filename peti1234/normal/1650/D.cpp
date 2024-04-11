#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int w, n, t[c], t2[c], ans[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=n; i>=1; i--) {
            int pos=0;
            for (int j=1; j<=i; j++) {
                if (t[j]==i) {
                    pos=j;
                }
            }
            int ert=pos%i;
            ans[i]=ert;
            for (int j=1; j<=i; j++) {
                int j2=(j+i-ert);
                if (j2>i) j2-=i;
                t2[j2]=t[j];
            }
            for (int j=1; j<=i; j++) {
                t[j]=t2[j];
            }
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}