#include <bits/stdc++.h>

using namespace std;
const int c=50005, c2=5000000;
int n, m, bl, cs=1, cnt;
long long po[52];
vector<long long> p;
vector<pair<long long, long long> > kerd[c];
vector<pair<int, int> > el[c];
vector<bool> ans;
int bal[c2], jobb[c2], id[c2], t[c2], ki[c2];
void add(int a, long long l, long long r, long long x, long long y) {
    if (x>=r || l>=y) {
        return;
    }
    if (x<=l && r<=y) {
        id[a]=++cnt;
        t[a]=bl;
        return;
    }
    if (!bal[a]) {
        bal[a]=++cs;
    }
    if (!jobb[a]) {
        jobb[a]=++cs;
    }
    long long mid=(l+r)/2;
    add(bal[a], l, mid, x, y);
    add(jobb[a], mid, r, x, y);
}
void add(long long x, long long y) {
    if (x>y) {
        return;
    }
    add(1, 0, po[n], x, y+1);
}
void dfs(int a, int b, int dif, int l) {
    if (id[a] && id[b]) {
        if (a!=b) {
            el[min(t[a], t[b])].push_back({id[a], id[b]});
        }
        return;
    }
    if (l==dif) {
        return dfs(bal[a], jobb[b], dif, l-1);
    }
    int a1=(bal[a] ? bal[a] : a), a2=(jobb[a] ? jobb[a] : a), b1=(bal[b] ? bal[b] : b), b2=(jobb[b] ? jobb[b] : b);
    dfs(a1, b1, dif, l-1);
    dfs(a2, b2, dif, l-1);
}
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
int ker(int a, int l, long long val) {
    if (id[a]) {
        return id[a];
    }
    int kov=((val & po[l]) ? jobb[a] : bal[a]);
    return ker(kov, l-1, val);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    po[0]=1;
    for (int i=1; i<=n; i++) {
        po[i]=po[i-1]*2;
    }
    p.push_back(-1), p.push_back(po[n]);
    for (int i=1; i<=m; i++) {
        string s;
        long long x, y;
        cin >> s >> x >> y;
        if (s=="block") {
            bl++;
            add(x, y);
            p.push_back(x), p.push_back(y);
        } else {
            kerd[bl].push_back({x, y});
        }
    }
    bl++;
    sort(p.begin(), p.end());
    for (int i=0; i<p.size(); i+=2) {
        add(p[i]+1, p[i+1]-1);
    }
    for (int i=0; i<n; i++) {
        dfs(1, 1, i, n-1);
    }

    for (int i=bl; i>=0; i--) {
        reverse(kerd[i].begin(), kerd[i].end());
        for (auto x:kerd[i]) {
            int a=ker(1, n-1, x.first), b=ker(1, n-1, x.second);
            ans.push_back(holvan(a)==holvan(b));
        }
        for (auto x:el[i]) {
            int a=x.first, b=x.second;
            unio(a, b);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x:ans) {
        cout << x << "\n";
    }
    return 0;
}