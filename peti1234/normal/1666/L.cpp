#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, kezd, fel[c], id[c];
vector<int> sz[c];
bool v[c];
void pr(vector<int> p) {
    int si=p.size();
    cout << si << "\n";
    for (int i=si-1; i>=0; i--) {
        cout << p[i] << " ";
    }
    cout << "\n";
}
void dfs(int a, int ert) {
    id[a]=ert;
    v[a]=true;
    for (auto x:sz[a]) {
        int s=(ert==0 ? x : ert);
        if (!v[x]) {
            fel[x]=a;
            dfs(x, s);
        } else if (x!=kezd && id[x]!=ert) {
            cout << "Possible\n";
            vector<int> p;
            p.push_back(x);
            int aa=a;
            while (aa!=kezd) {
                p.push_back(aa);
                aa=fel[aa];
            }
            p.push_back(kezd);
            pr(p);
            p.clear();
            aa=x;
            while (aa!=kezd) {
                p.push_back(aa);
                aa=fel[aa];
            }
            p.push_back(kezd);
            pr(p);
            exit(0);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> kezd;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
    }
    dfs(kezd, 0);
    cout << "Impossible\n";
    return 0;
}