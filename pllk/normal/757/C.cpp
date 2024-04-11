#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int n, m;
ll f[1111111];
vector<pair<int,int>> v[1111111];
map<vector<pair<int,int>>,int> z;

#define M 1000000007

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        f[i] = f[i-1]*i;
        f[i] %= M;
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        map<int,int> w;
        for (int j = 1; j <= c; j++) {
            int x;
            cin >> x;
            w[x]++;
        }
        for (auto u : w) {
            v[u.first].push_back({i,u.second});
        }
    }
    for (int i = 1; i <= m; i++) {
        z[v[i]]++;
    }
    ll r = 1;
    for (auto u : z) {
        r *= f[u.second];
        r %= M;
    }
    cout << r << "\n";
}