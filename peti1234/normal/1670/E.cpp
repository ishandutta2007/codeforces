#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int w, n, cs[c], el[c], cnt;
vector<pair<int, int> > sz[c];
bool v[c];
void dfs(int a, int ert) {
    v[a]=true;
    for (auto p:sz[a]) {
        int x=p.first, id=p.second;
        if (!v[x]) {
            cnt++;
            el[id]=cnt+ert;
            cs[x]=cnt+n-ert;
            dfs(x, n-ert);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        n=(1<<n);
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back({b, i});
            sz[b].push_back({a, i});
        }
        cs[1]=n;
        dfs(1, n);

        cout << 1 << "\n";
        for (int i=1; i<=n; i++) {
            cout << cs[i] << " ";
        }
        cout << "\n";
        for (int i=1; i<n; i++) {
            cout << el[i] << " ";
        }
        cout << "\n";

        for (int i=1; i<=n; i++) {
            cs[i]=0, el[i]=0;
            sz[i].clear();
            v[i]=0;
        }
        cnt=0;
    }
    return 0;
}