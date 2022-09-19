#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int w, n, m, k, n2;
vector<int> sz[c], vis;
bool v[c], fix[c];
int inv(int a) {
    return (a<=n2 ? a+n2 : a-n2);
}
void add(int a, int b) {
    sz[a].push_back(b);
    sz[inv(b)].push_back(inv(a));
}
void cl(int id) {
    for (auto x:vis) {
        v[x]=0;
        if (id) {
            fix[x]=1;
        }
    }
    vis.clear();
}
void dfs(int a) {
    vis.push_back(a);
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        n2=n*k;
        for (int i=1; i<=n; i++) {
            int s=k*(i-1)+1;
            add(s+n2, s);
        }

        for (int i=1; i<n; i++) {
            for (int j=1; j<=k; j++) {
                int s=k*(i-1)+j;
                add(s, s+k);
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=2; j<=k; j++) {
                int s=k*(i-1)+j;
                add(s, s-1);
            }
        }
        for (int q=1; q<=m; q++) {
            int id;
            cin >> id;
            if (id==1) {
                int pos, ert;
                cin >> pos >> ert;
                int s=k*(pos-1)+ert;
                if (ert<k) {
                    add(s, s+1);
                } else {
                    add(s, s+n2);
                }
            }
            if (id==2) {
                int p1, p2, ert;
                cin >> p1 >> p2 >> ert;
                for (int i=1; i<=k; i++) {
                    int s=k*(p1-1)+i;
                    int rem=ert-i;
                    if (rem>=k) continue;
                    if (rem<=0) {
                        add(s, s+n2);
                    } else {
                        add(s, k*(p2-1)+rem+1+n2);
                    }
                }
            }
            if (id==3) {
                int p1, p2, ert;
                cin >> p1 >> p2 >> ert;
                for (int i=1; i<=k; i++) {
                    int s=k*(p1-1)+i;
                    int rem=ert-i+1;
                    if (rem<=0) continue;
                    if (rem>k) {
                        add(s+n2, s);
                    } else {
                        add(s+n2, k*(p2-1)+rem);
                    }
                }
            }
        }
        bool baj=0;
        for (int i=1; i<=n2; i++) {
            if (!fix[i] && !fix[i+n2]) {
                dfs(i);
                if (!v[i+n2]) cl(1);
                else {
                    cl(0);
                    dfs(i+n2);
                    if (!v[i]) cl(1);
                    else {
                        cl(0);
                        baj=1;
                        break;
                    }
                }
            }
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            for (int i=1; i<=n; i++) {
                int ut=0;
                for (int j=1; j<=k; j++) {
                    int s=k*(i-1)+j;
                    if (fix[s]) ut=j;
                }
                cout << ut << " ";
            }
            cout << "\n";
        }

        for (int i=1; i<=2*n2; i++) {
            v[i]=0, fix[i]=0, sz[i].clear();
        }
    }
    return 0;
}