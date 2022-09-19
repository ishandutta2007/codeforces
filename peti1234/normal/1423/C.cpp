#include <bits/stdc++.h>

using namespace std;
const int c=10002;
int n, k, si[c];
vector<int> sz[c], akt, eler;
bool v[c], jo[c];
vector<pair<int, int> > sol;
void add(int a, int b) {
    if (a!=b) {
        sol.push_back({a, b});
    }
}
bool ures(int a) {
    return (!v[a] && !jo[a]);
}
void dfs2(int a) {
    eler.push_back(a);
    v[a]=true;
    for (int x:sz[a]) {
        if (ures(x)) {
            dfs2(x);
        }
    }
}
void dfs(int a, int gy) {
    v[a]=true;
    for (int x:sz[a]) {
        if (ures(x)) {
            dfs(x, gy);
            si[a]+=si[x];
        }
    }
    if (si[a]>=gy) {
        jo[a]=1;
        akt.push_back(a);
        si[a]=0;
    }
}
void solve(int a) {
    eler.clear(), akt.clear();
    dfs2(a);
    int cnt=eler.size(), gy=sqrt(cnt);
    for (int i:eler) {
        v[i]=0, si[i]=1;
    }
    if (cnt<=4) {
        for (int i:eler) {
            jo[i]=1;
        }
        return;
    }
    dfs(a, gy);
    for (int i:eler) {
        v[i]=0;
    }
    for (int i:akt) {
        for (int j:akt) {
            if (i>j) {
                add(i, j);
            }
        }
    }
    vector<int> eler2=eler;
    eler.clear();
    for (int i:akt) {
        dfs2(i);
        for (int j:eler) {
            add(i, j);
            v[j]=0;
        }
        eler.clear();
    }
    for (int i:eler2) {
        if (!jo[i]) {
            solve(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    solve(1);
    cout << sol.size() << "\n";
    for (auto i:sol) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}