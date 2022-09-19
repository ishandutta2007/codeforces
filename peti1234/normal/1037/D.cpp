#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> sz[200001];
int apa[200001];
int t[200001];
int ertek[200001];
void dfs(int a)
{
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (x!=apa[a]) {
            apa[x]=a;
            dfs(x);
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1;i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    dfs(1);
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        ertek[t[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        if(ertek[apa[t[i]]]>i) {
            cout << "NO" << endl;
            return 0;
        }
        if (i!=n && ertek[apa[t[i]]]>ertek[apa[t[i+1]]]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES";
    return 0;
}