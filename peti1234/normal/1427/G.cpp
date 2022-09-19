#include <bits/stdc++.h>

using namespace std;
const int c=40005;
int n, m, kov[c], t[c], f;
long long sum, db;
vector<int> sz[c], s[c], pos[c];
vector<pair<int, int> > ert;
bool v[c];
void add(int a, int b, int c, int d) {
    if (t[a]*t[b]!=0) return;
    int x=sz[a].size(), y=sz[b].size();
    pos[a].push_back(y), pos[b].push_back(x);
    sz[a].push_back(b), sz[b].push_back(a);
    s[a].push_back(c), s[b].push_back(d);
}
void el(int a, int b, int x) {
    s[a][b]-=x;
    s[sz[a][b]][pos[a][b]]+=x;
}
void cl() {
    for (int i=0; i<c; i++) v[i]=0;
}
bool dfs(int a) {
    v[a]=true;
    if (a==f) return true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v[x] && y) {
            if (dfs(x)) {
                el(a, i, 1);
                return true;
            }
        }
    }
    return false;
}
bool fdfs(int a) {
    v[a]=true;
    if (a==f) return true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v[x] && !y) {
            if (fdfs(x)) {
                el(a, i, -1);
                return true;
            }
        }
    }
    return false;
}
void valt(int a) {
    for (int i=0; i<sz[0].size(); i++) {
        if (sz[0][i]==a) {
            if (!s[0][i]) {
                cl();
                fdfs(a);
                cl();
                db--;
            } else el(0, i, 1);
        }
    }
    for (int i=0; i<sz[a].size(); i++) {
        if (sz[a][i]==f) el(a, i, -1);
    }
}
int main()
{
    cin >> n, f=n*n+1;
    for (int i=1; i<=n*n; i++) {
        cin >> t[i];
        if (t[i]>0) {
            add(0, i, 1, 0), add(i, f, 0, 1);
            if (i%n!=1 && t[i-1]>0) sum+=abs(t[i]-t[i-1]);
            if (i>n && t[i-n]>0) sum+=abs(t[i]-t[i-n]);
            ert.push_back({t[i], i});
        }
        if (t[i]!=-1) {
            if (i%n!=1 && t[i-1]!=-1) add(i, i-1, 1, 1);
            if (i>n && t[i-n]!=-1) add(i, i-n, 1, 1);
        }
    }
    sort(ert.begin(), ert.end());
    for (int i=0; i<4*n-5; i++) {
        int id=ert[i].second, cnt=ert[i+1].first-ert[i].first;
        valt(id), cl();
        while(dfs(0)) db++, cl();
        sum+=db*cnt;
    }
    cout << sum << "\n";
    return 0;
}