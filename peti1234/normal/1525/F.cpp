#include <bits/stdc++.h>

using namespace std;
const int c=105;
int n, m, k, par[c], si;
bool v[c], tilos[c];
vector<int> sz[c], sor, ans[c];
long long sum, sum2, mini=2e9, str, res, x[c], y[c], opt[c], minpos=1;
void cl() {
    for (int i=1; i<=2*n; i++) {
        v[i]=0;
    }
}
bool dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (tilos[x] || v[x]) {
            continue;
        }
        v[x]=1;
        if (!par[x] || dfs(par[x])) {
            par[a]=x, par[x]=a;
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b+n);
    }
    for (int i=1; i<=n; i++) {
        cl();
        dfs(i);
    }
    for (int i=1; i<=n; i++) {
        if (par[i]) {
            int s=par[i];
            tilos[s]=1;
            par[i]=0, par[s]=0;
            cl();
            if (!dfs(i)) {
                sor.push_back(-s+n);
            } else {
                tilos[s]=0, tilos[i]=1;
                par[par[i]]=0, par[i]=0;
                sor.push_back(i);
            }
        }
    }
    si=sor.size();
    for (int i=1; i<=k; i++) {
        cin >> x[i] >> y[i];
        sum+=x[i];
        if (y[i]<y[minpos]) {
            minpos=i;
        }
        if (sum2+x[i]<mini) {
            mini=sum2+x[i];
            str=i;
        }
        if (si+i>=n) {
            sum2+=y[minpos];
            opt[i]=minpos;
        }
    }
    if (sum2<mini) {
        mini=sum2;
        str=k+1;
    }

    for (int i=1; i<str; i++) {
        if (opt[i]) {
            res++;
            ans[opt[i]].push_back(sor.back());
            sor.pop_back();
        }
    }
    if (str<=k) {
        while (sor.size()>0) {
            res++;
            ans[str].push_back(sor.back());
            sor.pop_back();
        }
    }
    cout << res+k << "\n";
    for (int i=1; i<=k; i++) {
        for (int x:ans[i]) {
            cout << x << " ";
        }
        cout << 0 << " ";
    }
    cout << "\n";
    return 0;
}