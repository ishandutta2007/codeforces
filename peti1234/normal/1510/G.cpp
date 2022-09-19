#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w, n, k, marad, le[c], kov[c];
vector<int> sz[c], ans, ut;
bool v[c];
void dfs(int a) {
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            if (le[x]>=le[a]) {
                le[a]=le[x]+1;
                kov[a]=x;
            }
        }
    }
}
void dfs2(int a) {
    ans.push_back(a);
    for (int x:sz[a]) {
        if (!v[x] && marad>0) {
            marad--;
            dfs2(x);
            ans.push_back(a);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=2; i<=n; i++) {
            int x;
            cin >> x;
            sz[x].push_back(i);
        }
        dfs(1);
        int pos=1;
        while (pos) {
            v[pos]=1;
            ut.push_back(pos);
            pos=kov[pos];
        }
        int si=ut.size();
        marad=k-si;
        for (int cs:ut) {
            if (k) {
                k--;
                dfs2(cs);
            }
        }
        si=ans.size();
        cout << si-1 << "\n";
        for (auto x:ans) {
            cout << x << " ";
        }
        cout << "\n";

        marad=0, ans.clear(), ut.clear();
        for (int i=1; i<=n; i++) {
            v[i]=0, le[i]=0, kov[i]=0;
            sz[i].clear();
        }
    }
    return 0;
}