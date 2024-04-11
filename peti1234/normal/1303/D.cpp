#include <bits/stdc++.h>

using namespace std;
const int c=61;
long long po[c], w, db[c], n, m, sum, ans;
map<long long, int> inv;
int main()
{
    ios_base::sync_with_stdio(false);
    po[0]=1;
    inv[1]=0;
    for (int i=1; i<c; i++) {
        po[i]=po[i-1]*2;
        inv[po[i]]=i;
    }
    cin >> w;
    while (w--) {
        sum=0;
        cin >> n >> m;
        for (int i=0; i<c; i++) {
            db[i]=0;
        }
        for (int i=1; i<=m; i++) {
            long long x;
            cin >> x;
            sum+=x;
            db[inv[x]]++;
        }
        if (sum<n) {
            cout << -1 << "\n";
        } else {
            ans=0;
            for (long long ert=0; ert<c; ert++) {
                long long s=po[ert];
                if (n & s) {
                    int kov=ert;
                    while (!db[kov]) {
                        kov++;
                    }
                    ans+=kov-ert;
                    db[kov]--;
                    for (int j=ert; j<kov; j++) {
                        db[j]++;
                    }
                }
                db[ert+1]+=db[ert]/2;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
/*
1
10 3
1 32 1
*/