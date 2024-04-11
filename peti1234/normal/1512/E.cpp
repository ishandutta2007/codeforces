#include <bits/stdc++.h>

using namespace std;
const int c=502;
int w, n, l, r, s, tav;
bool spec[c], v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> l >> r >> s;
        tav=r-l+1;
        int mini=(tav+1)*tav/2;
        int maxi=mini+tav*(n-tav);
        if (mini>s || maxi<s) {
            cout << -1 << "\n";
        } else {
            for (int i=1; i<=n; i++) {
                spec[i]=0, v[i]=0;
            }
            for (int i=tav; i>=1; i--) {
                int dif=s-mini+i;
                for (int j=n; j>=1; j--) {
                    if (!spec[j] && j<=dif) {
                        spec[j]=1;
                        s-=j, mini-=i;
                        break;
                    }
                }
            }
            for (int i=1; i<l; i++) {
                for (int j=1; j<=n; j++) {
                    if (!spec[j] && !v[j]) {
                        cout << j << " ";
                        v[j]=1;
                        break;
                    }
                }
            }
            for (int i=1; i<=n; i++) {
                if (spec[i]) {
                    cout << i << " ";
                }
            }
            for (int i=r+1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (!spec[j] && !v[j]) {
                        cout << j << " ";
                        v[j]=1;
                        break;
                    }
                }
            }
            cout << "\n";
        }
    }
    return 0;
}