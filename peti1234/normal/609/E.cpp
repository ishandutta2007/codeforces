#include <bits/stdc++.h>

using namespace std;
const int c=200005, k=20;
long long sum;
vector<pair<int, pair<int, int> > > el, el2;
int n, m, ki[c], szint[c], fel[c][k], maxi[c][k];
vector<pair<int, int> > sz[c];
bool v[c];

int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        return 1;
    }
    return 0;
}

void dfs(int a) {
    v[a]=true;
    for (int i=1; i<k; i++) {
        int s=fel[a][i-1];
        fel[a][i]=fel[s][i-1];
        maxi[a][i]=max(maxi[a][i-1], maxi[s][i-1]);
    }
    for (auto p:sz[a]) {
        int x=p.first, y=p.second;
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a, maxi[x][0]=y;
            dfs(x);
        }
    }
}
int calc(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    int ans=0;
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            ans=max(ans, maxi[a][i]);
            a=fel[a][i];
        }
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            ans=max({ans, maxi[a][i], maxi[b][i]});
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a!=b) {
        ans=max({ans, maxi[a][0], maxi[b][0]});
    }
    return ans;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        el.push_back({c, {a, b}});
        el2.push_back({c, {a, b}});
    }
    sort(el.begin(), el.end());
    for (auto s:el) {
        int a=s.second.first, b=s.second.second, ert=s.first;
        if (unio(a, b)) {
            sum+=ert;
            sz[a].push_back({b, ert});
            sz[b].push_back({a, ert});
        }
    }

    szint[1]=1;
    dfs(1);

    for (auto s:el2) {
        int a=s.second.first, b=s.second.second, ert=s.first;
        int val=calc(a, b);
        cout << sum+ert-val << "\n";
    }
    return 0;
}