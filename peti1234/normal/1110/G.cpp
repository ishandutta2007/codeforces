#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int w, n, nf, lsz[c], vlsz, ldb, fdb, fix;
bool v[c];
vector<int> sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, nf=0, ldb=0, fdb=0, fix=0, vlsz=0;
        for (int i=1; i<=n; i++) v[i]=0, lsz[i]=0, sz[i].clear();
        for (int i=1; i<n; i++) {int a, b; cin >> a >> b; sz[a].push_back(b), sz[b].push_back(a);}
        for (int i=1; i<=n; i++) {
            if (sz[i].size()==1) ldb++, lsz[sz[i][0]]++;
            if (sz[i].size()>3) nf++;
        }
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            if (lsz[i]) vlsz++;
            if (c=='W') {
                if (sz[i].size()>1 || sz[sz[i][0]].size()>2) fix=1;
                fdb++;
            }
        }
        if ((n==3 && fdb==2) || ((n>3 && ((nf || fix || fdb>2 || vlsz>2) || (n%2 && ldb==4) || (n%2==0 && fdb==1 && ldb==3) || (fdb==2 && n%2))))) cout << "White\n";
        else cout << "Draw\n";
    }
    return 0;
}