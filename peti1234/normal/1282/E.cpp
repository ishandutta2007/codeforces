#include <bits/stdc++.h>

using namespace std;
int w, n, ut;
vector<pair<int, int> > sz[100001];
vector<int> sol;
vector<int> el[100001];
int szom[100001];
int db[100001];
bool v[100001];
bool h[100001];
void pb(int a, int b, int c) {
    sz[a].push_back({b, c});
    sz[b].push_back({a, c});
}
void epb(int a, int b) {
    el[a].push_back(b);
    el[b].push_back(a);
}
void dfs(int a) {
    cout << a << " ";
    v[a]=true;
    for (int i=0; i<el[a].size(); i++) {
        int x=el[a][i];
        if (!v[x]) {
            dfs(x);
            return;
        }
    }
}
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            sz[i].clear(), el[i].clear();
            szom[i]=0, db[i]=0, v[i]=false, h[i]=false;
        }
        sol.clear(), ut=0;
        while(q.size()>0) q.pop();
        for (int i=1; i<=n-2; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            pb(a, b, i), pb(b, c, i), pb(c, a, i);
            db[a]++, db[b]++, db[c]++;
        }
        for (int i=1; i<=n; i++) if (db[i]==1) q.push(i);
        for (int i=1; i<=n-2; i++) {
            int a=q.front();
            q.pop(), v[a]=true;
            int b=0, c=0, ans;
            for (int i=0; i<sz[a].size(); i++) {
                int x=sz[a][i].first, y=sz[a][i].second;
                if (!h[y]) ans=y;
                if (!v[x]) {
                    if (b) swap(b, c);
                    if (x!=b && x!=c) b=x;
                }
            }
            if (szom[a]!=b && szom[b]!=a) epb(a, b);
            if (szom[a]!=c && szom[c]!=a) epb(a, c);
            sol.push_back(ans), h[ans]=true;
            db[a]--, db[b]--, db[c]--;
            szom[b]=c, szom[c]=b;
            if (db[b]==1) q.push(b);
            if (db[c]==1) q.push(c);
            if (i==n-2) epb(b, c);
        }
        for (int i=1; i<=n; i++) v[i]=false;
        dfs(1);
        cout << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
        cout.flush() << "\n";
    }
    return 0;
}
/*
1 8
7 8 6
1 4 2
4 8 3
7 5 8
6 2 8
4 8 2
*/