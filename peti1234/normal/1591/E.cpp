#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int w, n, sn, q, ert[c], ans[c], db[c], fen[c];
vector<int> sz[c], ki[c];
vector<pair<pair<int, int>, int> > qu[c];
bool v[c];
int lsb(int a) {
    return (a & -a);
}
void add(int a, int ert) {
    if (!a) {
        return;
    }
    while (a<=n) {
        fen[a]+=ert;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}
int valt(int id, int p) {
    add(db[id], -1);
    db[id]+=p;
    add(db[id], 1);
    ki[db[id]].push_back(id);
}
void dfs(int a) {
    v[a]=true;
    valt(ert[a], 1);
    for (auto p:qu[a]) {
        int cel=ask(p.first.first-1)+p.first.second, id=p.second;
        if (ask(n)<cel) {
            ans[id]=-1;
        } else {
            int ert=0;
            for (int j=sn; j>=0; j--) {
                int kov=ert+(1<<j);
                if (kov<=n && fen[kov]<cel) {
                    ert=kov;
                    cel-=fen[kov];
                }
            }
            ert++;
            while (db[ki[ert].back()]!=ert) {
                ki[ert].pop_back();
            }
            ans[id]=ki[ert].back();
        }

    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    valt(ert[a], -1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> q;
        sn=0;
        while ((1<<sn)<n) sn++;
        for (int i=1; i<=n; i++) {
            cin >> ert[i];
        }
        for (int i=2; i<=n; i++) {
            int x;
            cin >> x;
            sz[i].push_back(x), sz[x].push_back(i);
        }
        for (int i=1; i<=q; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            qu[a].push_back({{b, c}, i});
        }
        dfs(1);
        for (int i=1; i<=q; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

        for (int i=1; i<=max(n, q); i++) {
            ert[i]=ans[i]=db[i]=fen[i]=v[i]=0;
            sz[i].clear(), qu[i].clear(), ki[i].clear();
        }
    }
    return 0;
}