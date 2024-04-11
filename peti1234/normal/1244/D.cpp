#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long n, t[c][4], res[c], ans=1e15;
vector<int> p, opt, sz[c], sor;
bool v[c];
void dfs(int a) {
    v[a]=true;
    sor.push_back(a);
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[j][i];
        }
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (sz[i].size()>2) {
            cout << -1 << "\n";
            return 0;
        }
    }
    for (int i=1; i<=n; i++) {
        if (sz[i].size()==1) {
            dfs(i);
            break;
        }
    }
    for (int i=1; i<=3; i++) {
        p.push_back(i);
    }
    do {
        long long sum=0;
        for (int i=0; i<n; i++) {
            sum+=t[sor[i]][p[i%3]];
        }
        if (sum<ans) {
            ans=sum;
            opt=p;
        }
    } while (next_permutation(p.begin(), p.end()));
    for (int i=0; i<n; i++) {
        res[sor[i]]=opt[i%3];
    }
    cout << ans << "\n";
    for (int i=1; i<=n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}