#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, si[c], t[c], p1, p2, db;
vector<int> sz[c];
queue<int> p, k;
bool v[c];
void pb(int a) {
    if (si[a]<2 && !v[a]) {
        if (t[a]!=1) p.push(a);
        if (t[a]!=2) k.push(a);
    }
}
void cl(int a) {
    if (!v[a]) {
        v[a]=1, db++;
        for (int i:sz[a]) {
            si[i]--;
            pb(i);
        }
    }
}
void clp() {
    if (db<n) p1++;
    while(p.size()) {
        int a=p.front();
        p.pop();
        cl(a);
    }
}
void clk() {
    if (db<n) p1++;
    while(k.size()) {
        int a=k.front();
        k.pop();
        cl(a);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, p1=0, p2=0, db=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sz[i].clear();
        }
        for (int i=1; i<n; i++) {
            int a, b; cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        for (int i=1; i<=n; i++) {
            v[i]=0, si[i]=sz[i].size();
            pb(i);
        }
        while(db<n) {
            clp();
            clk();
        }
        clp(), clk();
        p2=p1, p1=0, db=0;
        for (int i=1; i<=n; i++) {
            v[i]=0, si[i]=sz[i].size();
            pb(i);
        }
        while(db<n) {
            clk();
            clp();
        }
        clp(), clk();
        cout << min(p1, p2) << "\n";
    }
    return 0;
}