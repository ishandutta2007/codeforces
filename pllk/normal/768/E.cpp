#include <iostream>
#include <cstdlib>
#include <unordered_map>

using namespace std;

typedef long long ll;

int n;
int s[1111111];

unordered_map<ll,int> d[100];

int laske(int x, ll m) {
    if (x == 0) return 0;
    if (d[x].count(m)) return d[x][m];
    int g[100] = {0};
    for (int i = 1; i <= x; i++) {
        if (m&(1<<i)) continue;
        g[laske(x-i,m|(1<<i))] = 1;
    }
    int r;
    for (int i = 0; i < 100; i++) {
        if (g[i] == 0) {r = i; break;}
    }
    d[x][m] = r;
    return r;
}

int main() {
    for (int i = 0; i <= 60; i++) {
        laske(i,0);
    }
    scanf("%d",&n);
    int x = 0;
    for (int i = 1; i <= n; i++) {
        int s;
        scanf("%d",&s);
        x ^= laske(s,0);
    }
    if (x) cout << "NO\n";
    else cout << "YES\n";
}