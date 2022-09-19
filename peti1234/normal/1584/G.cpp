#include <bits/stdc++.h>

using namespace std;
const int c=3005;
long double pi=acos(-1), r;
long long n, xx[c], yy[c];
bool jo[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> r;
    for (int i=1; i<=n; i++) {
        cin >> xx[i] >> yy[i];
    }
    for (int i=1; i<=n; i++) {
        long double kis=0, nagy=4*pi;
        for (int j=1; j<=n; j++) {
            if (i==j) continue;
            long double x=xx[j]-xx[i], y=yy[j]-yy[i];
            long double tav=sqrt(x*x+y*y), ert=acos(x/tav);
            if (y<0) {
                ert=2*pi-ert;
            }
            if (tav<=r) continue;
            long double dif=asin(r/tav), kk=ert-dif, nn=ert+dif;
            if (kk<0 || nn<kis) kk+=2*pi, nn+=2*pi;
            kis=max(kis, kk), nagy=min(nagy, nn);
            //if (i==4) cout << i << " " << j << " " << kk << " " << nn << "\n";
        }
        /*if (nagy-kis>2*pi) {
            nagy-=2*pi;
        }*/
        //cout << "vege " << i << " " << kis << " " << nagy << "\n";
        for (int j=1; j<=n; j++) {
            if (i==j) continue;
            long double x=xx[j]-xx[i], y=yy[j]-yy[i];
            long double tav=sqrt(x*x+y*y), ert=acos(x/tav);
            if (y<0) {
                ert=2*pi-ert;
            }
            if (kis<=ert && ert<=nagy || kis<=ert+2*pi && ert+2*pi<=nagy) {
                jo[i][j]=1;
            }
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (jo[i][j] && jo[j][i]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}