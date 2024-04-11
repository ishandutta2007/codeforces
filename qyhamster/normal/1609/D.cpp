#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int fa[maxn], sz[maxn];
int ff(int x) {
    if(fa[x] == x) return x;
    return (fa[x] = ff(fa[x]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    int buf = 1;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(ff(x) != ff(y)) {
            int u = ff(x), v = ff(y);
            fa[v] = fa[u];
            sz[u] += sz[v];
            sz[v] = 0;
        }
        else buf++;
        vector<int> vec;
        for(int i = 1; i <= n; i++) {
            vec.push_back(sz[i]);
        }
        long long ans = 0;
        sort(vec.begin(), vec.end());
        for(int i = (int)vec.size()-1; i >= max(0, (int)vec.size()-buf); i--) ans += vec[i];
        cout << ans-1 << endl;
    }
    return 0;
}