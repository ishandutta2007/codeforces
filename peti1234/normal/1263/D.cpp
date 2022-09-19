#include <bits/stdc++.h>

using namespace std;
int n=26, q, db;
vector<int> sz[26];
bool v[26];
void dfs(int a) {
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) dfs(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=0; i<n; i++) v[i]=true;
    for (int i=1; i<=q; i++) {
        string s;
        cin >> s;
        int x=s[0]-'a';
        v[x]=false;
        for (int i=1; i<s.size(); i++) {
            int y=s[i]-'a'; v[y]=false;
            sz[x].push_back(y), sz[y].push_back(x);
        }
    }
    for (int i=0; i<n; i++) {
        if (!v[i]) dfs(i), db++;
    }
    cout << db << "\n";
    return 0;
}