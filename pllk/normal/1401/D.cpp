#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define M 1000000007

typedef long long ll;

int n;
vector<int> v[101010];
ll c[101010];
vector<ll> r;

void dfs(int s, int e) {
    c[s] = 1;
    for (auto u : v[s]) {
        if (u == e) continue;
        dfs(u,s);
        c[s] += c[u];
    }
    if (e != 0) r.push_back(c[s]*(n-c[s]));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int i = 1; i <= n-1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        r.clear();
        dfs(1,0);
        sort(r.begin(),r.end());
        int m;
        cin >> m;
        deque<ll> p(m);
        for (int i = 0; i < m; i++) cin >> p[i];
        sort(p.begin(),p.end());
        while (p.size() > n-1) {
            p[p.size()-2] *= p[p.size()-1];
            p.pop_back();
            p[p.size()-1] %= M;
        }
        while (p.size() < n-1) p.push_front(1);
        ll f = 0;
        for (int i = 0; i < n-1; i++) {
            f += r[i]%M*p[i]%M;
            f %= M;
        }
        cout << f << "\n";
    }
}