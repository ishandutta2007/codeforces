#include <bits/stdc++.h>

using namespace std;
int w, n, a[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        int mini=1e9;
        for (int e=0; e<2; e++) {
            for (int k=0; k<5; k++) {
                int h=0;
                for (int i=1; i<=n; i++) {
                    int ert=1e9;
                    for (int ee=0; ee<=e; ee++) {
                        for (int kk=0; kk<=k; kk++) {
                            int s=a[i]-ee-2*kk;
                            if (s>=0 && s%3==0) ert=min(ert, s/3);
                        }
                    }
                    h=max(h, ert);
                }
                mini=min(mini, h+e+k);
            }
        }
        cout << mini << "\n";
    }
    return 0;
}