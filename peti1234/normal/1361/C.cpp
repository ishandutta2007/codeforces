#include <bits/stdc++.h>

using namespace std;
const int c=500002, q=1050002;
vector<int> sz[q], s[q], sol;
vector<pair<int, int> > p;
bool v[c];
int n, t[2*c], pos[q];
void dfs(int a) {
    while(pos[a]<sz[a].size()) {
        int x=sz[a][pos[a]], y=s[a][pos[a]]; pos[a]++;
        if (!v[y]) {
            p.push_back({a, y});
            v[y]=true, dfs(x);
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=1; i<=2*n; i++) cin >> t[i];
    for (int k=20; k>=0; k--) {
        int f=(1<<k), el=t[1]%f, r=0;
        for (int i=1; i<=n; i++) v[i]=0;
        for (int i=0; i<f; i++) sz[i].clear(), s[i].clear(), pos[i]=0;
        sol.clear(), p.clear();
        for (int i=1; i<=n; i++) {
            int x=t[2*i-1]%f, y=t[2*i]%f;
            sz[x].push_back(y), sz[y].push_back(x), s[x].push_back(i), s[y].push_back(i);
        }
        for (int i=0; i<f; i++) if (sz[i].size()%2) r++;
        p.push_back({el, 0});
        while(p.size()>0) {
            int fi=p.back().first, se=p.back().second;
            p.pop_back(), dfs(fi), sol.push_back(se);
        }
        if (!r && sol.size()==n+1) {
            cout << k << "\n";
            for (int i=1; i<sol.size(); i++) {
                int x=2*sol[i]-1, y=2*sol[i];
                if (t[x]%f!=el) swap(x, y);
                cout << x << " " << y << " ", el=t[y]%f;
            }
            return 0;
        }
    }
    return 0;
}