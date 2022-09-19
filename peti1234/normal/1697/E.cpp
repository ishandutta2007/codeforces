#include <bits/stdc++.h>

using namespace std;
const int c=105;
long long n, x[c], y[c], mintav[c], alatt[c][c], fakt[c], db[5], ans, mod=998244353;
vector<int> sz[c];
long long tav(int a, int b) {
    if (a==b) {
        return 2e9;
    }
    return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=1; i<=n; i++) {
        long long ert=2e9;
        for (int j=1; j<=n; j++) {
            ert=min(ert, tav(i, j));
        }
        for (int j=1; j<=n; j++) {
            if (i==j || tav(i, j)==ert) {
                sz[i].push_back(j);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (sz[i][0]==i) {
            int si=sz[i].size();
            bool jo=1;
            for (auto x:sz[i]) {
                if (sz[x]!=sz[i]) {
                    jo=0;
                }
            }
            if (jo) {
                db[si]++;
            }
        }
    }
    fakt[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
    }
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            alatt[i][j]=(j==0 ? 1 : (alatt[i-1][j]+alatt[i-1][j-1])%mod);
        }
    }


    for (int a=0; a<=db[2]; a++) {
        for (int b=0; b<=db[3]; b++) {
            for (int c=0; c<=db[4]; c++) {
                long long cnt=n, cl=n, sum=1;
                sum=sum*alatt[db[2]][a]%mod*alatt[db[3]][b]%mod*alatt[db[4]][c]%mod*fakt[a]%mod*fakt[b]%mod*fakt[c]%mod;
                sum=sum*alatt[cl][a]%mod;
                cl-=a, cnt-=2*a;
                sum=sum*alatt[cl][b]%mod;
                cl-=b, cnt-=3*b;
                sum=sum*alatt[cl][c]%mod;
                cl-=c, cnt-=4*c;
                sum=sum*alatt[cl][cnt]%mod*fakt[cnt]%mod;
                //cout << "fontos " << a << " " << b << " " << c << " " << sum << "\n";
                ans=(ans+sum)%mod;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}