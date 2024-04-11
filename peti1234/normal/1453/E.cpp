#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, d[c], ml[c], maxi, msp;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    int ert=n;
    v[a]=true;
    if (sz[a].size()==1) {
        ert=d[a];
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            d[x]=d[a]+1;
            dfs(x);
            ml[a]=min(ml[a], ml[x]);
            int y=ml[x]-d[a];
            maxi=max(maxi, y);
            if (a==1 && msp<y) msp=y;
            else maxi=max(maxi, y+1);
            ert=min(ert, ml[x]);
        }
    }
    ml[a]=ert;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) d[i]=0, ml[i]=n+1, v[i]=0, maxi=0, msp=0, sz[i].clear();
        for (int i=1; i<n; i++) {
            int a, b; cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        cout << maxi << "\n";
    }
    return 0;
}
/*
1
6
1 2 2 3
1 4
1 5 5 6
*/