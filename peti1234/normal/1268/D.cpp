#include <bits/stdc++.h>

using namespace std;
const int c=2002;
bool v[c][c];
int n, db[c], db2[c], db3[c], ans;
bool jo() {
    bool baj=0;
    long long sum=0, cnt=0;
    for (int i=0; i<=n; i++) {
        cnt+=db3[i];
        sum+=db3[i]*i;
        db3[i]=0;
        if (cnt>0 && cnt<n && sum==cnt*(cnt-1)/2) {
            baj=1;
        }
    }
    return !baj;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;
            if (c=='1') {
                v[i][j]=1;
                db[i]++;
            }
        }
    }
    if (n<=8) {
        int mini=c;
        for (int mask=0; mask<(1<<n); mask++) {
            for (int i=1; i<=n; i++) {
                db2[i]=db[i];
            }
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if ((bool)(mask & (1<<(i-1))) != (bool)(mask & (1<<(j-1)))) {
                        db2[i]+=1-2*v[i][j];
                    }
                }
            }
            for (int i=1; i<=n; i++) {
                db3[db2[i]]++;
            }
            if (jo()) {
                int db=__builtin_popcount(mask);
                if (db<mini) {
                    mini=db;
                    ans=0;
                }
                if (db==mini) {
                    ans++;
                }
            }
        }
        if (mini==c) {
            cout << -1 << "\n";
        } else {
            for (int i=1; i<=mini; i++) {
                ans*=i;
            }
            cout << mini << " " << ans << "\n";
        }
    } else {
        for (int i=1; i<=n; i++) {
            db3[db[i]]++;
        }
        if (jo()) {
            cout << 0 << " " << 1 << "\n";
            return 0;
        } else {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    db2[j]=db[j];
                }
                for (int j=1; j<=n; j++) {
                    if (i==j) {
                        db2[j]=n-1-db2[j];
                    } else {
                        db2[j]+=1-2*v[j][i];
                    }
                }
                for (int j=1; j<=n; j++) {
                    db3[db2[j]]++;
                }
                if (jo()) {
                    ans++;
                }
            }
            cout << 1 << " " << ans << "\n";
        }
    }
    return 0;
}