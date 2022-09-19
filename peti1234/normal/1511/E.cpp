#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long n, m, pr, cnt, ans, mod=998244353;
long long ert[c], po[c];
vector<vector<int> > v, fel, bal;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    pr=n*m, po[0]=1, po[1]=2;
    for (int i=2; i<=pr; i++) {
        po[i]=po[i-1]*2%mod;
        ert[i]=ert[i-1]*2;
        if (i%2) {
            ert[i]--;
        } else {
            ert[i]++;
        }
        ert[i]%=mod;
    }
    v.resize(n), fel.resize(n), bal.resize(n);
    for (int i=0; i<n; i++) {
        v[i].resize(m), fel[i].resize(m), bal[i].resize(m);
        for (int j=0; j<m; j++) {
            char c;
            cin >> c;
            v[i][j]=(c=='o');
            if (v[i][j]) {
                cnt++;
                fel[i][j]=1;
                if (i>0) {
                    fel[i][j]+=fel[i-1][j];
                }
                bal[i][j]=1;
                if (j>0) {
                    bal[i][j]+=bal[i][j-1];
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int a=fel[i][j], b=bal[i][j];
            ans+=po[cnt-a]*ert[a]+po[cnt-b]*ert[b];
            ans%=mod;
        }
    }
    cout << ans << "\n";
    return 0;
}