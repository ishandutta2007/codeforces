#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, rf[c], kezd;
vector<int> sz[c];
void dfs(int a) {
    rf[a]=1;
    for (auto x:sz[a]) {
        dfs(x);
        rf[a]+=rf[x];
    }
}
void dfs2(int a) {
    for (auto x:sz[a]) {
        if (rf[x]%2==0) dfs2(x);
    }
    cout << a << " ";
    for (auto x:sz[a]) {
        if (rf[x]%2) dfs2(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x) sz[x].push_back(i);
        else kezd=i;
    }
    if (n%2) {
        dfs(kezd);
        cout << "YES\n";
        dfs2(kezd);
        cout << "\n";
    } else cout << "NO\n";
    return 0;
}