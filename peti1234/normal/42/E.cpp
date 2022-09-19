#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=20;
int n, m, w, fel[c][k], maxi[c][k], szint[c], comp, cs, ert;
long long sum;
vector<int> sz[c], s[c];
bool v[c];
priority_queue<pair<int, pair<int, int> > > q;
void add(int a, int b, int c) {
    q.push({-a, {b, c}});
}
int lep(int a, int b) {
    ert=max(ert, maxi[a][b]);
    return fel[a][b];
}
void lca(int a, int b) {
    cs=0, ert=0;
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            a=lep(a, i);
        }
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=lep(a, i), b=lep(b, i);
        }
    }
    if (a!=b) {
        a=lep(a, 0), b=lep(b, 0);
    }
    cs=a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        sz[a].push_back(b), sz[b].push_back(a);
        s[a].push_back(c), s[b].push_back(c);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            comp++;
            add(0, i, 0);
            while(q.size()>0) {
                int suly=-q.top().first, id=q.top().second.first, ki=q.top().second.second;
                q.pop();
                if (!v[id]) {
                    v[id]=true;
                    szint[id]=szint[ki]+1;
                    fel[id][0]=ki, maxi[id][0]=suly;
                    sum+=suly;
                    for (int i=1; i<k; i++) {
                        fel[id][i]=fel[fel[id][i-1]][i-1];
                        maxi[id][i]=max(maxi[id][i-1], maxi[fel[id][i-1]][i-1]);
                    }
                    for (int i=0; i<sz[id].size(); i++) {
                        int x=sz[id][i], y=s[id][i];
                        if (!v[x]) {
                            add(y, x, id);
                        }
                    }
                }
            }
        }
    }
    cin >> w;
    for (int i=1; i<=w; i++) {
        int a, b; cin >> a >> b;
        lca(a, b);
        if (comp==1) {
            cout << sum-ert << "\n";
        }
        if (comp==2) {
            if (cs) {
                cout << -1 << "\n";
            } else {
                cout << sum << "\n";
            }
        }
        if (comp>2) {
            cout << -1 << "\n";
        }
    }
    return 0;
}
/*
3
1
1 2 3
1
1 2
*/