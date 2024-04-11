#include <bits/stdc++.h>

using namespace std;
int n, m;
int k[101];
bool v[101];
bool c;
vector<int> p;
vector<int> sz[101];
vector<int> s[101];
void dfs(int a)
{
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        int y=s[a][i];
        if (v[x]) {
            if ((y+k[a]+k[x])%2==0) {
                c=true;
            }
        } else {
            if ((y+k[a])%2==0) {
                k[x]=1;
            } else {
                k[x]=0;
            }
            dfs(x);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b);
        sz[b].push_back(a);
        s[a].push_back(c);
        s[b].push_back(c);
    }
    for (int i=1; i<=n; i++) {
        k[i]=-1;
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            k[i]=1;
            dfs(i);
        }
    }
    if (c) {
        cout << "Impossible" << endl;
    } else {
        for (int i=1; i<=n; i++) {
            if (k[i]==1) {
                p.push_back(i);
            }
        }
        cout << p.size() << endl;
        for (int i=0; i<p.size(); i++) {
            cout << p[i] << " ";
        }
    }
    return 0;
}