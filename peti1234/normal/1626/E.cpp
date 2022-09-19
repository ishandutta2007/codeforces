#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n;
vector<int> sz[c], f;
bool v[c], spec[c], jo[c];
void dfs(int a, bool b) {
    v[a]=true;
    if (spec[a]) b=1;
    for (auto x:sz[a]) {
        if (spec[x]) b=1;
    }
    if (b) {
        jo[a]=1;
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x, b);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> spec[i];
        if (spec[i]) f.push_back(i);
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        int db=spec[i];
        for (auto x:sz[i]) db+=spec[x];
        if (db>1) {
            for (int i=1; i<=n; i++) {
                cout << 1 << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    for (int i=0; i<2; i++) {
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
        spec[f[i]]=0;
        dfs(f[i], 0);
        spec[f[i]]=1;
    }
    for (int i=1; i<=n; i++) {
        cout << jo[i] << " ";
    }
    cout << "\n";
    return 0;
}