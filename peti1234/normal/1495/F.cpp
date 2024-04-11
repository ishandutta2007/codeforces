#include <bits/stdc++.h>

using namespace std;
const int c=200002, k=20;
int n, q, p[c], szint[c], fel[c][k], f[c], db[c];
long long aa[c], bb[c], dist[c], val[c], sum;
bool v[c];
set<int> s;
int lca(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            a=fel[a][i];
        }
    }
    if (a==b) {
        return a;
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    return f[a];
}
long long tav(int a, int b) {
    int koz=lca(a, b);
    return dist[a]+dist[b]-2*dist[koz];
}
void keres(int a, int &l, int &r) {
    auto it=s.find(a);
    --it;
    l=*it;
    ++it, ++it;
    if (it!=s.end()) {
        r=*it;
    }
}
void add(int a) {
    s.insert(a);
    int l=0, r=0;
    keres(a, l, r);
    sum+=tav(l, a)+tav(a, r)-tav(l, r);
}
void cl(int a) {
    int l=0, r=0;
    keres(a, l, r);
    sum-=tav(l, a)+tav(a, r)-tav(l, r);
    s.erase(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    p[0]=n+1;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        f[i]=i-1;
        while (p[i]>p[f[i]]) {
            f[i]=f[f[i]];
        }
        szint[i]=szint[f[i]]+1;
        fel[i][0]=f[i];
        for (int j=1; j<k; j++) {
            fel[i][j]=fel[fel[i][j-1]][j-1];
        }
    }
    for (int i=1; i<=n; i++) {
        cin >> aa[i];
        val[i]+=aa[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> bb[i];
        val[i]-=bb[i];
        val[f[i]]+=bb[i];
    }
    for (int i=n; i>=1; i--) {
        if (val[i]<0) {
            val[f[i]]+=val[i];
            val[i]=0;
        }
    }
    for (int i=1; i<=n; i++) {
        dist[i]=dist[f[i]]+val[i];
    }
    db[0]=1;
    s.insert(0);
    for (int i=1; i<=q; i++) {
        int x; cin >> x;
        if (!v[x]) {
            v[x]=1;
            if (++db[f[x]]==1) {
                add(f[x]);
            }
        } else {
            v[x]=0;
            if (--db[f[x]]==0) {
                cl(f[x]);
            }
        }
        cout << sum/2+val[0] << "\n";
    }
    return 0;
}