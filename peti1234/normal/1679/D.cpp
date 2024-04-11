#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, ert[c], sor[c], len[c], cnt, spec;
long long k;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x] && ert[x]<=spec) {
            dfs(x);
        }
        if (ert[x]<=spec) {
            len[a]=max(len[a], len[x]+1);
        }
    }
    sor[a]=++cnt;
}
bool solve(int mid) {
    spec=mid;
    for (int i=1; i<=n; i++) {
        if (!v[i] && ert[i]<=spec) {
            dfs(i);
        }
    }
    bool kor=0;
    for (int i=1; i<=n; i++) {
        if (ert[i]>spec) continue;
        for (auto x:sz[i]) {
            if (sor[x]>sor[i]) kor=1;
        }
    }
    int maxi=-1;
    for (int i=1; i<=n; i++) {
        if (ert[i]>spec) continue;
        maxi=max(maxi, len[i]);
    }
    bool jo=(kor || maxi+1>=k);
    cnt=0;
    for (int i=1; i<=n; i++) {
        v[i]=0;
        sor[i]=0, len[i]=0;
    }
    return jo;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
    }
    int lo=0, hi=1e9+1, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (solve(mid)) hi=mid;
        else lo=mid;
    }
    cout << (hi>1e9 ? -1 : hi) << "\n";
    return 0;
}