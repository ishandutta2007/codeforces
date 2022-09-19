#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long sum=0;
int n, t[c], inv[c], be[c], ki[c], cnt, fel[c], le[c], szint[c], mini[c], pos=1, spec, cnt2, cnt3;
vector<int> sz[c];
bool baj;
bool f(int a, int b) {
    return t[a]<t[b];
}
void dfs(int a) {
    be[a]=++cnt, mini[a]=a;
    for (int x:sz[a]) {
        le[a]++, fel[x]=a;
        szint[x]=szint[a]+1;
        dfs(x);
        mini[a]=min(mini[a], mini[x]);
    }
    ki[a]=cnt;
}
void dfs2(int a) {
    if (t[a]>spec) {
        cnt2++;
        if (t[a]!=cnt2) {
            baj=1;
        }
    }
    for (int x:sz[a]) {
        dfs2(x);
    }
    cnt3++;
    if (t[a]<spec) {
        if (t[a]!=cnt3) {
            baj=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        inv[t[i]]=i;
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        sort(sz[i].begin(), sz[i].end(), f);
    }
    dfs(1);
    for (int i=1; i<=n; i++) {
        int kov=inv[i];
        sum+=szint[kov];
        if (le[kov]) {
            spec=i;
            cnt2=spec;
            break;
        }
        pos=fel[kov];
        le[pos]--;
    }
    if (!spec) {
        spec=n, cnt2=spec;
    }
    dfs2(1);
    if (baj) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << sum << "\n";
        for (int i=1; i<=n; i++) {
            cout << be[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}