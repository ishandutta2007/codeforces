#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m;
int a[101010];
int b[101010];

int si[202020];
int pa[202020];

int id(int x) {
    while (x != pa[x]) x = pa[x];
    return x;
}

void merge(int a, int b) {
    a = id(a);
    b = id(b);
    if (a == b) return;
    if (si[a] < si[b]) swap(a,b);
    pa[b] = a;
    si[a] += si[b];
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<int>> v;
    ll t = 0;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            v.push_back({a[i]+b[x],i,x});
            t += v.back()[0];
        }
    }
    sort(v.rbegin(),v.rend());
    for (int i = 1; i <= n+m; i++) {
        si[i] = 1;
        pa[i] = i;
    }
    for (auto x : v) {
        int a = n+x[1];
        int b = x[2];
        if (id(a) == id(b)) continue;
        t -= x[0];
        merge(a,b);
    }
    cout << t << "\n";
}