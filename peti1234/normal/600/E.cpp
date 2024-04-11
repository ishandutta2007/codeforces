#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, cl[c], ki[c], si[c];
long long ans[c];
vector<int> sz[c];
bool v[c];
map<int, long long> db[c], ert[c];
void unio(int a, int b) {
    int aa=ki[a], bb=ki[b];
    if (si[aa]<si[bb]) {
        swap(aa, bb);
    }
    //cout << "unio " << aa << " " << bb << "\n";
    for (auto x:db[bb]) {
        int fi=x.first, se=x.second;
        ert[aa][db[aa][fi]]-=fi;
        db[aa][fi]+=se;
        ert[aa][db[aa][fi]]+=fi;
    }
    si[aa]+=si[bb];
    ki[a]=aa;
}
void dfs(int a) {
    ki[a]=a, si[a]=1;
    db[a][cl[a]]=1, ert[a][1]=cl[a];
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            unio(a, x);
        }
    }
    for (auto x:ert[ki[a]]) {
        ans[a]=x.second;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> cl[i];
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    for (int i=1; i<=n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
/*
2
1 2
1 2
*/