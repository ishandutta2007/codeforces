#include <bits/stdc++.h>

using namespace std;
const int c=200002, k=20;
int n, q, t[c], db[c], el[c], ut[c], lg[c], cnt, mini[c][k], maxi;
bool baj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        maxi=max(maxi, t[i]);
    }
    for (int i=1; i<=n; i++) {
        if (!t[i] && maxi!=q) t[i]=q, maxi=q;
    }
    if (!t[1]) t[1]=1;
    for (int i=2; i<=n; i++) {
        if (!t[i]) t[i]=t[i-1];
        lg[i]=lg[i/2]+1;
    }
    for (int i=n; i>=1; i--) {
        if (!ut[t[i]]) ut[t[i]]=i;
        el[t[i]]=i;
        mini[i][0]=t[i];
        for (int j=1; i+(1<<j)<=n+1; j++) {
            int s=i+(1<<(j-1));
            mini[i][j]=min(mini[i][j-1], mini[s][j-1]);
        }
    }
    for (int i=1; i<=q; i++) {
        if (el[i]) {
            int a=el[i], b=ut[i], s=lg[b-a+1], ert=min(mini[a][s], mini[b-(1<<s)+1][s]);
            if (ert<i) baj=1;
        }
    }
    if (maxi!=q || baj) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}