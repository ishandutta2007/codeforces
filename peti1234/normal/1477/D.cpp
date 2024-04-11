#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int w, n, m, el[c], kov[c], p1[c], p2[c], cnt;
bool jo[c], spec[c], v[c], h[c];
set<int> s[c];
vector<int> sz[c];
queue<int> q;
void add(int a) {
    q.push(a);
    jo[a]=true, kov[el[a]]=kov[a], el[kov[a]]=el[a];
}
void dfs(int a) {
    v[a]=true;
    vector<int> k;
    int kezd=cnt;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            if (!h[x]) {
                k.push_back(x);
            }
        }
    }
    if (k.size()>0) {
        cnt++;
        p1[a]=cnt;
        h[a]=1;
        for (int x:k) {
            p1[x]=cnt+1;
            p2[x]=cnt;
            cnt++;
        }
        p2[a]=cnt;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        kov[0]=1;
        for (int i=1; i<=n; i++) {
            el[i]=i-1, kov[i]=i+1;
        }
        cnt=0;
        for (int i=1; i<=n; i++) {
            s[i].clear(), sz[i].clear();
            p1[i]=p2[i]=jo[i]=spec[i]=v[i]=h[i]=0;
        }
        for (int i=1; i<=m; i++) {
            int a, b; cin >> a >> b;
            s[a].insert(b), s[b].insert(a);
        }
        for (int i=1; i<=n; i++) {
            if (!jo[i]) {
                add(i);
            }
            while (q.size()>0) {
                int a=q.front(); q.pop();
                for (int i=kov[0]; i<=n; i=kov[i]) {
                    if (!jo[i] && s[a].find(i)==s[a].end()) {
                        sz[a].push_back(i), sz[i].push_back(a);
                        add(i);
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            if (sz[i].size()==1) {
                spec[sz[i][0]]=1;
            }
        }
        for (int i=1; i<=n; i++) {
            if (spec[i] && !v[i]) {
                dfs(i);
            }
            if (sz[i].size()==0) {
                cnt++;
                p1[i]=p2[i]=cnt;
            }
        }
        for (int i=1; i<=n; i++) {
            cout << p1[i] << " ";
        }
        cout << "\n";
        for (int i=1; i<=n; i++) {
            cout << p2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
1
4 2
1 2
3 4
*/