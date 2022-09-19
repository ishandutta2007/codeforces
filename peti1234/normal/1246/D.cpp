#include <bits/stdc++.h>

using namespace std;
const int c=200002;
vector<int> sz[c], sol, s;
int n, si, ki[c], f[c], md[c];
bool v[c];
void dfs(int a) {
    v[a]=1;
    cout << a << " ";
    int pos=-1;
    s.push_back(a);
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (pos==-1 && md[x]+1==md[a]) pos=x;
        if (pos!=x) dfs(x);
    }
    if (pos!=-1) dfs(pos);
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int x; cin >> x;
        ki[i]=x;
        sz[x].push_back(i);
    }
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<sz[i].size(); j++) {
            md[i]=max(md[i], md[sz[i][j]]+1);
        }
    }
    dfs(0);
    cout << "\n";
    for (int i=1; i<n; i++) f[s[i]]=s[i-1];
    for (int i=1; i<n; i++) {
        int x=s[i];
        while(f[x]!=ki[x]) {
            sol.push_back(x);
            f[x]=f[f[x]];
        }
    }
    cout << sol.size() << "\n";
    for (int i:sol) cout << i << " ";
    cout << "\n";
    return 0;
}