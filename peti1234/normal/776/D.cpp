#include <bits/stdc++.h>

using namespace std;

const int c=500005;
int n, m, kezd[c];
vector<int> sz[c], vis, el[c];
bool v[c], fix[c];
int inv(int a) {
    return (a<=n ? a+n : a-n);
}
void add(int a, int b) {
    sz[a].push_back(b);
    sz[inv(b)].push_back(inv(a));
}
void cl(int id) {
    for (auto x:vis) {
        v[x]=0;
        if (id) {
            fix[x]=1;
        }
    }
    vis.clear();
}
void dfs(int a) {
    vis.push_back(a);
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
bool sat() {
    bool jo=1;
    for (int i=1; i<=n; i++) {
        if (!fix[i] && !fix[i+n]) {
            dfs(i);
            if (!v[i+n]) cl(1);
            else {
                cl(0);
                dfs(i+n);
                if (!v[i]) cl(1);
                else {
                    cl(0);
                    jo=0;
                    break;
                }
            }
        }
    }
    return jo;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i=1; i<=m; i++) {
        cin >> kezd[i];
    }
    for (int i=1; i<=n; i++) {
        int s;
        cin >> s;
        for (int j=1; j<=s; j++) {
            int x;
            cin >> x;
            el[x].push_back(i);
        }
    }
    for (int i=1; i<=m; i++) {
        int a=el[i][0], b=el[i][1];
        if (kezd[i]) add(a, b), add(b, a);
        else add(a, b+n), add(b+n, a);
    }
    cout << (sat() ? "YES" : "NO") << "\n";
    return 0;
}