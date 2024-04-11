#include <bits/stdc++.h>

using namespace std;
const int c=100002, f=10*c;
int n, m, ans[c], ki[c], fel[c], eler[c], visz[c], cnt;
bool v[c];
vector<int> sz[c], s[c], volt;
vector<pair<pair<int, int>, int> > suly[f];
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    return ki[a]=holvan(ki[a]);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
    return;
}
void dfs(int a) {
    volt.push_back(a);
    v[a]=true;
    cnt++;
    eler[a]=cnt, visz[a]=cnt;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], id=s[a][i];
        if (!v[x]) {
            fel[x]=id;
            dfs(x);
            if (visz[x]>eler[a]) {
                ans[id]++;
            }
            visz[a]=min(visz[a], visz[x]);
        } else if (id!=fel[a]) {
            visz[a]=min(visz[a], eler[x]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, ert;
        cin >> a >> b >> ert;
        suly[ert].push_back({{a, b}, i});
    }
    for (int i=1; i<f; i++) {
        if (suly[i].size()==0) {
            continue;
        }
        for (auto j:suly[i]) {
            int a=j.first.first, b=j.first.second, id=j.second;
            a=holvan(a), b=holvan(b);
            if (a!=b) {
                sz[a].push_back(b), s[a].push_back(id);
                sz[b].push_back(a), s[b].push_back(id);
                ans[id]++;
            }
        }
        for (auto j:suly[i]) {
            int a=j.first.first;
            if (!v[a]) {
                dfs(a);
            }
        }
        cnt=0;
        for (auto j:volt) {
            v[j]=fel[j]=eler[j]=visz[j]=0;
            sz[j].clear(), s[j].clear();
        }
        volt.clear();
        for (auto j:suly[i]) {
            int a=j.first.first, b=j.first.second;
            unio(a, b);
        }
    }
    for (int i=1; i<=m; i++) {
        if (ans[i]==0) {
            cout << "none";
        }
        if (ans[i]==1) {
            cout << "at least one";
        }
        if (ans[i]==2) {
            cout << "any";
        }
        cout << "\n";
    }
    return 0;
}