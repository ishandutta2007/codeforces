#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
int s;
set<pair<int,int>> e;
vector<int> v[101010];
int z[101010];
int c;

void dfs(int x) {
    if (z[x]) return;
    z[x] = 1;
    c++;
    for (auto u : v[x]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a,b);
        if (e.count({a,b})) continue;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (z[i]) continue;
        c = 0;
        dfs(i);
        s += c-1;
    }
    cout << k-s << "\n";
}