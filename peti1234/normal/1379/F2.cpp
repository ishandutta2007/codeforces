#include <bits/stdc++.h>

using namespace std;
const int c=1<<19;
int p1, p2, n, x[c], y[c], cnt;
int kezd[c], veg[c];
vector<int> sq[c];
map<pair<int, int>, int> m;
vector<int> fen[c][3], valt;
void pb(int a, int l, int r, int ert) {
    if (kezd[a]>r || veg[a]<l) return;
    if (l<=kezd[a] && veg[a]<=r) sq[a].push_back(ert);
    else pb(2*a, l, r, ert), pb(2*a+1, l, r, ert);
}
int lsb(int a) {
    return (a & -a);
}
void add(int h, int a, int b) {
    while (a<c) {
        int kov=(h==1 ? min(fen[a][h].back(), b) : max(fen[a][h].back(), b));
        fen[a][h].push_back(kov);
        a+=lsb(a);
    }
}
int ask(int h, int a) {
    int ans=(h==1 ? c : 0);
    while (a) {
        ans=(h==1 ? min(ans, fen[a][h].back()) : max(ans, fen[a][h].back()));
        a-=lsb(a);
    }
    return ans;
}
void cl(int h, int a) {
    while (a<c) {
        fen[a][h].pop_back();
        a+=lsb(a);
    }
}
void dfs(int a) {
    for (auto p:sq[a]) {
        int xx=x[p], yy=y[p];
        int s=0;
        if (xx%2 && ask(2, c-xx)>yy) s=1;
        if (xx%2==0 && ask(1, xx)<=yy) s=1;
        valt.push_back(s);
        cnt+=s;
        if (xx%2) add(1, xx, yy);
        else add(2, c-xx, yy);
    }
    if (kezd[a]!=veg[a]) {
        dfs(2*a);
        dfs(2*a+1);
    } else if (1<=kezd[a] && kezd[a]<=n) {
        cout << (cnt ? "NO" : "YES") << "\n";
    }
    for (auto p:sq[a]) {
        int xx=x[p], yy=y[p];
        cnt-=valt.back();
        valt.pop_back();
        if (xx%2) cl(1, xx);
        else cl(2, c-xx);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> p1 >> p2 >> n;
    int po=1;
    while (po<=n) po*=2;
    for (int i=po; i<2*po; i++) kezd[i]=veg[i]=i-po;
    for (int i=po-1; i>=1; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        pair<int, int> p={x[i], y[i]};
        if (m.count(p)) {
            pb(1, m[p], i-1, i);
            m.erase(p);
        } else m[p]=i;
    }
    for (auto x:m) {
        pb(1, x.second, n, x.second);
    }
    for (int i=1; i<c; i++) fen[i][1].push_back(c), fen[i][2].push_back(0);
    dfs(1);
    return 0;
}