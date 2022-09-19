#include <bits/stdc++.h>

using namespace std;
#define rep(n) for (int i=1; i<=n; i++)
const int c=200002;
int w, n, cnt, db, t[c][2], si, r;
vector<int> sz[c], ut;
bool v[c], cs[c];
void dfs(int a, bool pos) {
    ut.push_back(a), v[a]=1;
    if (pos) cnt++, cs[a]=1;
    int ert=t[a][pos], x=sz[ert][0], y=sz[ert][1];
    if (a!=x) {
        if (!v[x]) {
            if (t[x][0]==ert) dfs(x, 1);
            else dfs(x, 0);
        }
    } else {
        if (!v[y]) {
            if (t[y][0]==ert) dfs(y, 1);
            else dfs(y, 0);
        }
    }
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, db=0, r=0;
        rep(n) sz[i].clear(), v[i]=0, cs[i]=0, t[i][0]=0, t[i][1]=0;
        rep(n) cin >> t[i][0], sz[t[i][0]].push_back(i);
        rep(n) cin >> t[i][1], sz[t[i][1]].push_back(i);
        rep(n) if (sz[i].size()!=2) r++;
        if (r) {cout << -1 << "\n"; continue;}
        rep(n) if (!v[i]) {
            cnt=0, ut.clear();
            dfs(i, 0), si=ut.size();
            if (2*cnt>si) for (int i=0; i<si; i++) cs[ut[i]]=!cs[ut[i]];
        }
        rep(n) db+=cs[i];
        cout << db << "\n";
        rep(n) if (cs[i]) cout << i << " ";
        cout << "\n";
    }
    return 0;
}