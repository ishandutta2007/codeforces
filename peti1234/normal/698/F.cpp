#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long ans=1, mod=1e9+7;
int n, pro[c], prcsop[c], csop[c], ki[c], inv[c];
vector<int> pr[c];
void ns() {
    cout << 0 << "\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) pro[i]=1;
    pr[1].push_back(1);
    prcsop[1]++, csop[1]++;
    for (int i=2; i<=n; i++) {
        if (pro[i]==1) {
            prcsop[n/i]++;
            for (int j=i; j<=n; j+=i) {
                pro[j]*=i;
                pr[j].push_back(i);
            }
        }
        //cout << i << " " << pro[i] << "\n";
        csop[pro[i]]++;
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x) {
            if (pr[i].size()!=pr[x].size()) ns();
            for (int j=0; j<pr[x].size(); j++) {
                int a=pr[x][j], b=pr[i][j];
                int aa=(a==1 ? 1 : n/a), bb=(b==1 ? b : n/b);
                if (ki[a] && ki[a]!=b || inv[b] && inv[b]!=a || aa!=bb) ns();
                if (!ki[a]) prcsop[(aa)]--;
                ki[a]=b, inv[b]=a;
            }
            csop[pro[x]]--;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=prcsop[i]; j++) ans=ans*j%mod;
        for (int j=1; j<=csop[i]; j++) ans=ans*j%mod;
    }
    cout << ans << "\n";
    return 0;
}