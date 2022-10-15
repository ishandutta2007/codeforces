#include <iostream>
#include <vector>

using namespace std;

#define M 998244353

typedef long long ll;

int n;
vector<int> v[202020];
int d[202020];
ll f[202020];

ll t = 1;

void dfs(int s, int e) {
    d[s] = 1;
    int h = 0;
    for (auto u : v[s]) {
        if (u == e) continue;
        dfs(u,s);
        d[s] += d[u];
        h++;
    }
    if (s == 1) {
        t *= d[s];
        t %= M;
        t *= f[h];
        t %= M;
    } else if (d[s] > 1) {
        t *= (h+1);
        t %= M;
        t *= f[h];
        t %= M;
    }
}

int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i-1]*i)%M;
    }
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    cout << t << "\n";
}