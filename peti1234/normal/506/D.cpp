#include <bits/stdc++.h>

using namespace std;
const int c=100002;
unordered_map<int, int> ki[c], s[c];
vector<int> sz[c], sz2[c];
int n, m, q;
int holvan(int a, int b) {
    if (!ki[a][b] || ki[a][b]==a) {
        return a;
    }
    ki[a][b]=holvan(ki[a][b], b);
    return ki[a][b];
}
void unio(int a, int b, int c) {
    a=holvan(a, c), b=holvan(b, c);
    if (a!=b) {
        ki[a][c]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    bool spec=0;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        sz[a].push_back(c), sz[b].push_back(c);
        unio(a, b, c);
    }
    for (int i=1; i<=n; i++) {
        sort(sz[i].begin(), sz[i].end());
        for (int j=0; j<sz[i].size(); j++) {
            int f=sz[i][j];
            if (j==0 || f!=sz[i][j-1]) {
                sz2[i].push_back(f);
                holvan(i, f);
                if (!ki[i][f]) {
                    ki[i][f]=i;
                }
            }
        }
    }
    int sum=0;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b; cin >> a >> b;
        if (sz2[a].size()>sz2[b].size()) {
            swap(a, b);
        }
        if (s[a].find(b)==s[a].end()) {
            int db=0;
            for (int i:sz2[a]) {
                if (ki[a].find(i)!=ki[a].end() && ki[b].find(i)!=ki[b].end()) {
                    db+=(ki[a][i]==ki[b][i]);
                }
            }
            s[a][b]=db;
        }
        cout << s[a][b] << "\n";
    }
    return 0;
}