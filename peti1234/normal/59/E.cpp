#include <bits/stdc++.h>

using namespace std;
const int c=50002;
int hm[10*c], n, m, k, fel[c], kezd;
bool vel[c], vcs[c];
pair<int, int> elek[c];
vector<int> sz[c], f[c], sol;
queue<pair<int, int> > q;
void ujel(int a, int b, int id) {
    elek[id]={a, b};
    long long x=(a*1919+b)%(10*c);
    while(hm[x]) {
        x++;
        if (x==10*c) x=0;
    }
    hm[x]=id;
}
int ki(int a, int b) {
    long long x=(a*1919+b)%(10*c);
    pair<int, int> p={a, b};
    while(hm[x]) {
        if (elek[hm[x]]==p) {
            return hm[x];
        }
        x++;
        if (x==10*c) x=0;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
        ujel(a, b, i), ujel(b, a, i+m);
    }
    for (int i=1; i<=k; i++) {
        int a, b, c, x, y;
        cin >> a >> b >> c;
        x=ki(a, b);
        if (x) {
            f[x].push_back(c);
        }
    }
    for (int i=1; i<=n; i++) sort(sz[i].begin(), sz[i].end());
    for (int i=1; i<=2*m; i++) sort(f[i].begin(), f[i].end());
    q.push({0, 1});
    while(q.size()>0) {
        int a=q.front().first, b=q.front().second, id=ki(a, b);
        q.pop();
        if (!vcs[b]) {
            vcs[b]=1;
            if (b==n) kezd=a;
        }
        int pos=0, si=f[id].size();
        for (int x:sz[b]) {
            while(pos<si && f[id][pos]<x) pos++;
            if (pos==si || f[id][pos]!=x) {
                int el=ki(b, x);
                if (!vel[el]) {
                        q.push({b, x});
                    fel[el]=a, vel[el]=1;
                }
            }
        }
    }
    if (!kezd) {
        cout << -1 << "\n";
        return 0;
    }
    sol.push_back(n);
    int a=kezd, b=n;
    while(a) {
        sol.push_back(a);
        int id=ki(a, b), uj=fel[id];
        b=a, a=uj;
    }
    int si=sol.size();
    cout << si-1 << "\n";
    for (int i=si-1; i>=0; i--) cout << sol[i] << " ";
    cout << "\n";
    return 0;
}