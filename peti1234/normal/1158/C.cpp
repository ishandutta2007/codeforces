#include <bits/stdc++.h>

using namespace std;
int n;
int t[500002];
int ans[500002];
vector<int> sz[500002];
int akt=0;
vector<int> p;
void dfs(int a)
{
    ans[a]=akt;
    akt--;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        dfs(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int l=1; l<=q; l++) {
        p.clear();
        cin >> n;
        bool c=true;
        p.push_back(n+1);
        for (int i=1; i<=n+1; i++) {
            sz[i].clear();
        }
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            int a=t[i];
            if (a==-1) {
                a=i+1;
            }
            if (i==p.back()) {
                p.pop_back();
            }
            if (a>p.back()) {
                c=false;
            }
            if (a<p.back()) {
                p.push_back(a);
            }
            sz[a].push_back(i);
            ans[i]=0;
        }
        if (c) {
        akt=n+1;
        dfs(n+1);
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}