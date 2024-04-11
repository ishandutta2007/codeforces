#include <bits/stdc++.h>

using namespace std;
int valt(char c) {
    int x=c-'a', y=c-'A', z=c-'0';
    if (x>=0 && x<=26) return x+1;
    if (y>=0 && y<=26) return y+31;
    return z+61;
}
char vvalt(int a) {
    char x='a', y='A', z='0';
    if (a<30) return x-1+a;
    if (a<60) return y-1+a-30;
    return z-1+a-60;
}
const int c=10002, k=200002;
int n=c-2, m, be[c], ki[c], pos[c], st, dif, si;
vector<int> sz[c], p, sol;
bool v[k];
void dfs(int a) {
    while(pos[a]<sz[a].size()) {
        int x=sz[a][pos[a]];
        pos[a]++;
        p.push_back(x);
        dfs(x);
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m;
    for (int i=1; i<=m; i++) {
        string ss; cin >> ss;
        int x=valt(ss[0]), y=valt(ss[1]), z=valt(ss[2]);
        int p=100*x+y, q=100*y+z;
        ki[p]++, be[q]++;
        sz[p].push_back(q);
    }
    for (int i=1; i<=n; i++) {
        if (ki[i]>be[i] || (ki[i] && !st)) st=i;
        dif+=max(0, ki[i]-be[i]);
    }
    sz[0].push_back(st);
    dfs(0);
    while(p.size()>0) {
        int id=p.back();
        dfs(id);
        p.pop_back(), sol.push_back(id%100);
    }
    si=sol.size();
    if (dif>1 || si!=m+1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << vvalt(st/100);
    for (int i=m; i>=0; i--) {
        cout << vvalt(sol[i]);
    }
    cout << "\n";
    return 0;
}