#include <bits/stdc++.h>

using namespace std;
const int c=4010, f=2005;
long long w, n, db[f][c], sum[f][c], mod=1e9+7;
string x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> x >> y;
        db[0][f]=1;
        for (int i=0; i<n; i++) {
            int a=(x[i]!='0' && y[i]!='1'), b=(x[i]!='0' && y[i]!='0')+(x[i]!='1' && y[i]!='1'), c=(x[i]!='1' && y[i]!='0');
            if (i%2) swap(a, c);
            for (int ert=f-n; ert<=f+n; ert++) {
                long long x=db[i][ert], y=sum[i][ert];
                if (x) {
                    db[i+1][ert-1]=(db[i+1][ert-1]+a*x)%mod;
                    sum[i+1][ert-1]=(sum[i+1][ert-1]+a*(y+x*abs(f-(ert-1))))%mod;

                    db[i+1][ert]=(db[i+1][ert]+b*x)%mod;
                    sum[i+1][ert]=(sum[i+1][ert]+b*(y+x*abs(f-(ert))))%mod;

                    db[i+1][ert+1]=(db[i+1][ert+1]+c*x)%mod;
                    sum[i+1][ert+1]=(sum[i+1][ert+1]+c*(y+x*abs(f-(ert+1))))%mod;
                }
            }
        }
        //cout << "valasz.................. ";
        cout << sum[n][f] << "\n";
        for (int i=0; i<=n; i++) {
            for (int j=f-n; j<=f+n; j++) {
                db[i][j]=0, sum[i][j]=0;
            }
        }
    }
    return 0;
}