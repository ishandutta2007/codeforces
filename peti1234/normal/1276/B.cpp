#include <bits/stdc++.h>

using namespace std;
int w;
vector<int> sz[200001];
bool v[200001];
int si[200001];
long long sum, sump, sumq;
int n, m, p, q;
bool dfs(int a)
{
    si[a]++;
    bool ans=1;
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (x==q) ans=0;
        if (!v[x]) {
            bool y=dfs(x);
            if (!y) ans=0;
            si[a]+=si[x];
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m >> p >> q;
        for (int i=1; i<=n; i++) sz[i].clear(), v[i]=0, si[i]=0;
        v[p]=true, v[q]=true;;
        sum=0, sump=0, sumq=0;
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        for (int i=0; i<sz[p].size(); i++) {
            int a=sz[p][i];
            if (!v[a]) {
                bool x=dfs(a);
                sump+=x*si[a];
            }
        }
        for (int i=0; i<sz[q].size(); i++) {
            int a=sz[q][i];
            if (!v[a]) {
                dfs(a);
                sumq+=si[a];
            }
        }
        cout << sump*sumq << "\n";
    }
    return 0;
}