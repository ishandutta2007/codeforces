#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, ert[c], ki[c], ans;
bool v[c];
vector<int> sz[c];
set<int> s[c];
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
bool unio(int a, int b) {
    //cout << "unio " << a << " " << b << "\n";
    int val=ert[a];
    a=holvan(a), b=holvan(b);
    if (s[a].size()<s[b].size()) swap(a, b);
    bool jo=0;
    for (auto x:s[b]) {
        if (s[a].find(x^val)!=s[a].end()) {
            jo=1;
        }
    }
    for (auto x:s[b]) {
        s[a].insert(x);
    }
    ki[b]=a;
    return jo;
}
void dfs(int a, int b) {
    bool spec=0;
    v[a]=true;
    b^=ert[a];
    s[a].insert(b);
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x, b);
            if (unio(a, x)) {
                spec=1;
            }

        }
    }
    if (spec) {
        ans++;
        s[holvan(a)].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> ert[i];
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}
/*
2
1 1
1 2
*/