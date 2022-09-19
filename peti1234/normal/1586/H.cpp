#include <bits/stdc++.h>

using namespace std;
const int c=200005, k=20, sok=2e9;
int n, q, e[c];
vector<pair<int, pair<int, int> > > s;
int szint[c], fel[c][k], val[c][k];
vector<pair<int, int> > sz[c];
bool v[c];
int ki[c], ert[c];
pair<int, int> ans[c];

void dfs(int a) {
    v[a]=true;
    for (int i=1; i<k; i++) {
        int s=fel[a][i-1];
        fel[a][i]=fel[s][i-1];
        val[a][i]=max(val[a][i-1], val[s][i-1]);
    }
    for (auto p:sz[a]) {
        int x=p.first, y=p.second;
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a, val[x][0]=y;
            dfs(x);
        }
    }
}

int tav(int a, int b) {
    int ans=0;
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            ans=max(ans, val[a][i]);
            a=fel[a][i];
        }
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            ans=max({ans, val[a][i], val[b][i]});
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a!=b) {
        ans=max({ans, val[a][0], val[b][0]});
    }
    return ans;
}


int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (e[b]>e[a]) {
        swap(a, b);
    }
    ki[b]=a;
    if (e[a]==e[b]) {
        ert[a]=max({ert[a], ert[b], tav(a, b)});
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> e[i];
    }
    for (int i=1; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        sz[a].push_back({b, d});
        sz[b].push_back({a, d});
        s.push_back({c, {a, b}});
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        s.push_back({a, {-i, b}});
    }
    sort(s.rbegin(), s.rend());
    for (auto x:s) {
        int a=x.second.first, b=x.second.second;
        if (a>0) {
            unio(a, b);
        } else {
            int p=holvan(b);
            ans[-a]={e[p], max(ert[p], tav(b, p))};
        }
    }
    for (int i=1; i<=q; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}