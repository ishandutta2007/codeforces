#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, maxi, pos=c, cnt, id[c], szint[c], kezd;
vector<int> sz[c];
bool v[c], v2[c], jo[c];
void dfs2(int a) {
    v2[a]=true;
    bool s=jo[a];
    for (int x:sz[a]) {
        if (!v2[x]) {
            dfs2(x);
            if (jo[x]) {
                s=1;
            }
        }
    }
    jo[a]=s;
    cnt+=jo[a]*2;
}
void dfs(int a) {
    if (!jo[a]) {
        return;
    }
    v[a]=true;
    int x1=a, x2=a;
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x);
            int aa=szint[x1], bb=szint[x2], cc=szint[id[x]];
            if (cc>bb || (cc==bb && id[x]<x2)) {
                x2=id[x];
                if (cc>aa || (cc==aa && id[x]<x1)) {
                    swap(x1, x2);
                }
            }
        }
    }
    id[a]=x1;
    int s=szint[x1]+szint[x2]-2*szint[a];
    if (s>maxi || (s==maxi && min(x1, x2)<pos)) {
        maxi=s;
        pos=min(x1, x2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=m; i++) {
        int x; cin >> x;
        kezd=x;
        jo[x]=1;
    }
    dfs2(kezd), cnt-=2;
    szint[kezd]=1, dfs(kezd);
    cout <<  pos << "\n" << cnt-maxi << "\n";
    return 0;
}