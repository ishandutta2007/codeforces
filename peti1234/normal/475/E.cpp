#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, m, maxi, pl, si[c], rf[c], ki[c], eler[c], visz[c], f[c], cnt, ans;
vector<int> sz[c], sz2[c];
bool v[c], ks[c];
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        si[b]+=si[a], si[a]=0;
    }
}
void dfs(int a) {
    v[a]=true, cnt++;
    eler[a]=cnt, visz[a]=cnt;
    for (int x:sz[a]) {
        if (!v[x]) {
            f[x]=a;
            dfs(x);
            visz[a]=min(visz[a], visz[x]);
            if (visz[x]!=eler[x]) {
                unio(a, x);
            }
        } else {
            if (f[a]!=x) {
                visz[a]=min(visz[a], eler[x]);
            }
        }
    }
}
void dfs2(int a, bool s) {
    v[a]=true;
    rf[a]+=si[a];
    for (int x:sz2[a]) {
        if (!v[x]) {
            dfs2(x, 0);
            ans+=si[a]*rf[x];
            rf[a]+=rf[x];
            if (s) {
                for (int i=n; i>=0; i--) {
                    if (ks[i]) {
                        ks[i+rf[x]]=1;
                    }
                }
            }
        }
    }
    if (s) {
        int add=0;
        for (int i=0; i<n; i++) {
            if (ks[i]) {
                add=max(add, i*(n-si[a]-i));
            }
        }
        ans+=add;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        si[i]=1;
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    for (int i=1; i<=n; i++) {
        pl+=si[i]*si[i];
        for (int j:sz[i]) {
            int a=holvan(i), b=holvan(j);
            if (a!=b) {
                sz2[a].push_back(b);
            }
        }
    }
    ks[0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            v[j]=0, rf[j]=0, ks[j]=0;
        }
        ans=0;
        dfs2(i, 1);
        maxi=max(maxi, ans);
    }
    cout << maxi+pl << "\n";
    return 0;
}