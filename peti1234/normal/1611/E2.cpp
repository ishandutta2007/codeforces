#include <bits/stdc++.h>

using namespace std;
const int c=200005, k=20;
int w, n, szint[c], fel[c][k], sp[c], s;
vector<int> sz[c], ord;
bool v[c], jo[c];
void dfs(int a) {
    ord.push_back(a);
    v[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        for (int i=1; i<=s; i++) cin >> sp[i];
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        szint[1]=1;
        dfs(1);
        for (int i=1; i<=s; i++) {
            int ert=sp[i], cel=szint[ert]/2+1;
            for (int j=k-1; j>=0; j--) if (szint[fel[ert][j-1]]>=cel) ert=fel[ert][j-1];
            jo[ert]=1;
        }
        bool baj=0;
        int cnt=0;
        for (auto x:ord) {
            if (x==1) continue;
            if (jo[fel[x][0]]) jo[x]=1;
            else if (jo[x]) cnt++;
            else if (sz[x].size()==1) baj=1;
        }
        //cout << (baj ? "YES" : "NO") << "\n";
        cout << (baj ? -1 : cnt) << "\n";
        for (int i=1; i<=n; i++) {
            sz[i].clear();
            szint[i]=0, sp[i]=0, v[i]=0, jo[i]=0;
            for (int j=0; j<k; j++) fel[i][j]=0;
        }
        ord.clear();
    }
    return 0;
}
/*
1
3 2
2 3
3 1
1 2
*/