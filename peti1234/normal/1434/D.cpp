#include <bits/stdc++.h>

using namespace std;
const int c=(1<<20);
int n, q, po=1;
vector<int> sz[c];
vector<pair<int, int> > s[c];

int leut[c], lecs[c], maxtav, cs1, cs2;
bool v[c], vv[c][2];
int be[c][2], ki[c][2], elinv[c][2], cnt[2], tav[c][2];
int kezd[c], veg[c], maxi[c][2], mini[c][2];
bool ford[c][2];
void dfs(int a) {
    v[a]=true;
    int tav=0, cs=a;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            if (leut[x]+tav+1>maxtav) {
                maxtav=leut[x]+tav+1;
                cs1=lecs[x], cs2=cs;
            }
            if (leut[x]+1>tav) {
                tav=leut[x]+1, cs=lecs[x];
            }
        }
    }
    leut[a]=tav, lecs[a]=cs;
}
void init(int po) {
    for (int i=po; i<2*po; i++) {
        kezd[i]=i-po+1, veg[i]=kezd[i];
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
}
void alap(int pos, int ert, int id) {
    if (pos==0) {
        return;
    }
    if (pos>=po) {
        maxi[pos][id]=ert;
    } else {
        maxi[pos][id]=max(maxi[2*pos][id], maxi[2*pos+1][id]);
    }
    alap(pos/2, ert, id);
}
void recalc(int a, int id) {
    swap(maxi[a][id], mini[a][id]);
    maxi[a][id]*=-1, mini[a][id]*=-1;
    return;
}
void valt(int a, int bal, int jobb, int id) {
    int l=kezd[a], r=veg[a];
    if (l>jobb || r<bal) {
        return;
    }
    if (bal<=l && r<=jobb) {
        ford[a][id]=!ford[a][id];
        recalc(a, id);
        return;
    }
    int x=2*a, y=2*a+1;
    valt(x, bal, jobb, id), valt(y, bal, jobb, id);
    maxi[a][id]=max(maxi[x][id], maxi[y][id]);
    mini[a][id]=min(mini[x][id], mini[y][id]);
    if (ford[a][id]) {
        recalc(a, id);
    }
}
void dfs2(int a, int id) {
    vv[a][id]=1;
    cnt[id]++;
    be[a][id]=cnt[id];
    alap(po+be[a][id]-1, tav[a][id], id);
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], elid=s[a][i].first, tip=s[a][i].second;
        if (!vv[x][id]) {
            tav[x][id]=tav[a][id]+1;
            elinv[elid][id]=x;
            dfs2(x, id);
            if (tip) {
                valt(1, be[x][id], ki[x][id], id);
            }
        }
    }
    ki[a][id]=cnt[id];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (po<n) {
        po*=2;
    }
    init(po);
    for (int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b), sz[b].push_back(a);
        s[a].push_back({i, c}), s[b].push_back({i, c});
    }
    dfs(1);
    dfs2(cs1, 0), dfs2(cs2, 1);

    cin >> q;
    for (int i=1; i<=q; i++) {
        int elid;
        cin >> elid;
        for (int j=0; j<2; j++) {
            int s=elinv[elid][j];
            valt(1, be[s][j], ki[s][j], j);
        }
        cout << max(maxi[1][0], maxi[1][1]) << "\n";
    }
    return 0;
}