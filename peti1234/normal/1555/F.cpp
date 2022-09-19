#include <bits/stdc++.h>

using namespace std;
const int c=(1<<20), k=c/2, lg=20;
int n, m, hv[c], aa[c], bb[c], xo[c];
int kezd[c], veg[c], maxi[c];
int cnt, be[c], ki[c], fel[c], ert[c], szint[c], fel2[c][lg];
vector<pair<int, int> > sz[c];
bool v[c], jo[c];

int holvan(int a) {
    return (hv[a] ? hv[a]=holvan(hv[a]) : a);
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        hv[b]=a;
        return true;
    }
    return false;
}

void dfs(int a) {
    v[a]=true;
    be[a]=++cnt;
    fel2[a][0]=fel[a];
    for (int i=1; i<lg; i++) {
        fel2[a][i]=fel2[fel2[a][i-1]][i-1];
    }
    for (auto p:sz[a]) {
        int x=p.first, y=p.second;
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x]=a;
            ert[x]=(ert[a]^y);
            dfs(x);
        }
    }
    ki[a]=cnt;
}

int lca(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=lg-1; i>=0; i--) {
        if (szint[fel2[a][i]]>=szint[b]) {
            a=fel2[a][i];
        }
    }
    if (a==b) {
        return a;
    }
    for (int i=lg-1; i>=0; i--) {
        if (fel2[a][i]!=fel2[b][i]) {
            a=fel2[a][i], b=fel2[b][i];
        }
    }
    return fel[a];
}
int calc(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) {
        return 0;
    }
    if (l<=kezd[a] && veg[a]<=r) {
        return 2;
    }
    return 1;
}
void add(int a, int l, int r, int ert) {
    int s=calc(a, l, r);
    if (s==0) {
        return;
    }
    if (s==2) {
        maxi[a]=max(maxi[a], ert);
    } else {
        add(2*a, l, r, ert), add(2*a+1, l, r, ert);
    }
}
int ask(int a, int b) {
    int s=calc(a, b, b);
    if (s==0) {
        return 0;
    }
    if (s==2) {
        return maxi[a];
    }
    return max({maxi[a], ask(2*a, b), ask(2*a+1, b)});
}
void init(int x) {
    int po=1;
    while (po<x) {
        po*=2;
    }
    for (int i=po; i<2*po; i++) {
        kezd[i]=i-po+1, veg[i]=kezd[i];
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> aa[i] >> bb[i] >> xo[i];
        int a=aa[i], b=bb[i], c=xo[i];
        if (unio(a, b)) {
            jo[i]=1;
            sz[a].push_back({b, c});
            sz[b].push_back({a, c});
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            szint[i]=1;
            dfs(i);
        }
    }
    init(n);
    for (int i=1; i<=m; i++) {
        int a=aa[i], b=bb[i], c=xo[i];
        if (jo[i] || (ert[a]^ert[b]^c)!=1) {
            continue;
        }
        int x=lca(a, b);
        if (ask(1, be[a])<=be[x] && ask(1, be[b])<=be[x]) {
            jo[i]=1;
            while (a!=x) {
                add(1, be[a], ki[a], be[a]);
                a=fel[a];
            }
            while (b!=x) {
                add(1, be[b], ki[b], be[b]);
                b=fel[b];
            }
        }
    }
    for (int i=1; i<=m; i++) {
        cout << (jo[i] ? "YES" : "NO") << "\n";
    }
    return 0;
}