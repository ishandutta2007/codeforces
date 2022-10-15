#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int n;
ll s;
vector<pair<int,ll>> v[101010];
int c[101010];
priority_queue<vector<ll>> q;
ll d;

void dfs(int s, int e) {
    c[s] = 0;
    int f = 0;
    for (auto u : v[s]) {
        if (u.first == e) continue;
        f = 1;
        dfs(u.first,s);
        c[s] += c[u.first];
        d += c[u.first]*u.second;
        ll w = c[u.first]*(u.second/2+u.second%2);
        q.push({w,c[u.first],u.second});
    }
    if (f == 0) c[s] = 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }
        for (int i = 1; i <= n-1; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        while (q.size()) q.pop();
        d = 0;
        dfs(1,0);
        int c = 0;
        while (d > s) {
            auto f = q.top();
            q.pop();
            d -= f[0];
            c++;
            f[2] /= 2;
            q.push({f[1]*(f[2]/2+f[2]%2),f[1],f[2]});
        }
        cout << c << "\n";
    }
}