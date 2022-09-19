#include <bits/stdc++.h>

using namespace std;
const int c=305, k=2000002, c2=c*c;
vector<pair<pair<int, int>, int> > sz[2][k];
int t[c][c], n, m, q, kom[k];
void add(int s, int a, int b, int ert, int i) {
    sz[s][ert].push_back({{a, b}, i});
}
int valt(int a, int b) {
    if (a<1 || a>n || b<1 || b>m) {
        return 0;
    }
    return (a-1)*m+b;
}
int si[c2], ki[c2];
bool v[c2];
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    return ki[a]=holvan(ki[a]);
}
int unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (si[a]<si[b]) {
        swap(a, b);
    }
    if (a!=b) {
        ki[b]=a;
        si[a]+=si[b];
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            add(0, i, j, 0, 0);
        }
    }
    for (int i=1; i<=q; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        add(1, a, b, t[a][b], i);
        add(0, a, b, p, i);
        t[a][b]=p;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            add(1, i, j, t[i][j], q+1);
        }
    }
    for (int pr=0; pr<2; pr++) {
        for (int i=0; i<k; i++) {
            if (sz[pr][i].size()==0) {
                continue;
            }
            if (pr) {
                reverse(sz[pr][i].begin(), sz[pr][i].end());
            }
            for (int j=0; j<=n*m; j++) {
                si[j]=1, ki[j]=0, v[j]=0;
            }
            int mul=(pr==0 ? 1 : -1);
            for (auto cs:sz[pr][i]) {
                int a=cs.first.first, b=cs.first.second, ido=cs.second;
                int ert=valt(a, b);
                int db=1;
                int ks=valt(a-1, b), ko=valt(a, b-1), ns=valt(a+1, b), no=valt(a, b+1);
                v[ert]=1;
                if (v[ks]) {
                    db-=unio(ert, ks);
                }
                if (v[ko]) {
                    db-=unio(ert, ko);
                }
                if (v[ns]) {
                    db-=unio(ert, ns);
                }
                if (v[no]) {
                    db-=unio(ert, no);
                }
                kom[ido]+=mul*db;
            }
        }
    }
    for (int i=1; i<=q; i++) {
        kom[i]+=kom[i-1];
        cout << kom[i] << "\n";
    }
    return 0;
}