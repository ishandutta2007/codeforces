#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=21;
int n, q, be[c][k], ki[c][k], szint[c], uel[c], ert[2*c], besz, kisz, utsz, invbe[c], invki[c];
pair<int, int> ut[2*c][k];
vector<int> sz[c];
void dfs(int a) {
    besz++, be[a][0]=besz, invbe[besz]=a;
    utsz++, uel[a]=utsz, ut[utsz][0]={szint[a], a};
    for (int x:sz[a]) {
        szint[x]=szint[a]+1;
        dfs(x);
        utsz++, ut[utsz][0]={szint[a], a};
    }
    kisz++, ki[a][0]=kisz, invki[kisz]=a;
}
pair<int, int> lca(int a, int b) {
    if (!a) return ut[uel[b]][0];
    if (!b) return ut[uel[a]][0];
    int l=uel[a], r=uel[b], s;
    if (l>r) swap(l, r);
    s=ert[r-l+1];
    return min(ut[l][s], ut[r+1-(1<<s)][s]);
}
int rlca(int l, int r) {
    if (l>r) return 0;
    int bv, jv, s;
    s=ert[r-l+1];
    bv=invki[max(ki[l][s], ki[r+1-(1<<s)][s])];
    jv=invbe[min(be[l][s], be[r+1-(1<<s)][s])];
    return lca(bv, jv).second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=2; i<=n; i++) {
        int x; cin >> x;
        sz[x].push_back(i);
    }
    dfs(1);
    for (int i=2; i<=2*n; i++) {
        ert[i]=ert[i/2]+1;
    }
    for (int j=1; j<k; j++) {
        int s=(1<<(j-1));
        for (int i=1; i+(1<<j)<=n+1; i++) {
            be[i][j]=min(be[i][j-1], be[i+s][j-1]);
            ki[i][j]=max(ki[i][j-1], ki[i+s][j-1]);
        }
        for (int i=1; i+(1<<j)<=2*n; i++) {
            ut[i][j]=min(ut[i][j-1], ut[i+s][j-1]);
        }
    }
    for (int i=1; i<=q; i++) {
        int l, r, bv, jv, bert, jert, s; cin >> l >> r;
        s=ert[r-l+1];
        bv=invki[max(ki[l][s], ki[r+1-(1<<s)][s])], bert=lca(rlca(l, bv-1), rlca(bv+1, r)).first;
        jv=invbe[min(be[l][s], be[r+1-(1<<s)][s])], jert=lca(rlca(l, jv-1), rlca(jv+1, r)).first;
        if (bert>jert) {
            cout << bv << " " << bert << "\n";
        } else {
            cout << jv << " " << jert << "\n";
        }
    }
    return 0;
}