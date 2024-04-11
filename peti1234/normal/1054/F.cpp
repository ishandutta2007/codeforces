#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int p, n1, n2, jo1, jo2, n, par[c];
vector<pair<int, int> > s, o;
vector<int> sl, ol;
vector<pair<int, pair<int, int> > > s2, o2;
vector<int> sz[c];
bool v[c], jo[c];
bool dfs(int a) {
    for (auto x:sz[a]) {
        if (!v[x]) {
            v[x]=1;
            if (!par[x] || dfs(par[x])) {
                par[a]=x, par[x]=a;
                return 1;
            }
        }
    }
    return 0;
}
dfs2(int a) {
    v[a]=true;
    jo[a]=1;
    for (auto x:sz[a]) {
        if (!v[x]) {
            v[x]=1, jo[x]=0;
            dfs2(par[x]);
        }
    }
}
int main()
{
    cin >> p;
    sl.resize(p), ol.resize(p);
    for (int i=1; i<=p; i++) {
        int x, y;
        cin >> x >> y;
        s.push_back({x, y}), o.push_back({y, x});
    }
    sort(s.begin(), s.end());
    for (int i=1; i<p; i++) {
        if (s[i].first==s[i-1].first) {
            s2.push_back({s[i].first, {s[i-1].second, s[i].second}});
            sl[i-1]=++n;
        }
    }
    sort(o.begin(), o.end());
    for (int i=1; i<p; i++) {
        if (o[i].first==o[i-1].first) {
            o2.push_back({o[i].first, {o[i-1].second, o[i].second}});
            ol[i-1]=++n;
        }
    }
    n1=s2.size(), n2=o2.size();
    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            auto x=s2[i], y=o2[j];
            if (y.second.first<x.first && x.first<y.second.second && x.second.first<y.first && y.first<x.second.second) {
                sz[i+1].push_back(n1+j+1), sz[n1+j+1].push_back(i+1);
            }
        }
    }
    for (int i=1; i<=n1; i++) {
        dfs(i);
        for (int j=1; j<=n; j++) {
            v[j]=0;
        }
    }

    for (int i=1; i<=n1; i++) {
        jo[i]=1;
    }
    for (int i=n1+1; i<=n; i++) {
        if (!jo[i] && !par[i]) {
            dfs2(i);
        }
    }
    for (int i=1; i<=n; i++) {
        if (jo[i]) {
            (i<=n1 ? jo1++ : jo2++);
        }
    }

    cout << p-jo2 << "\n";
    int veg=0;
    for (int i=0; i<p; i=veg+1) {
        veg=i;
        while (jo[ol[veg]]) {
            veg++;
        }
        cout << o[i].second << " " << o[i].first << " " << o[veg].second << " " << o[veg].first << "\n";
    }

    cout << p-jo1 << "\n";
    veg=0;
    for (int i=0; i<p; i=veg+1) {
        veg=i;
        while (jo[sl[veg]]) {
            veg++;
        }
        cout << s[i].first << " " << s[i].second << " " << s[veg].first << " " << s[veg].second << "\n";
    }


    return 0;
}