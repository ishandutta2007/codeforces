#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int n;
int a[121212];

map<vector<int>,ll> mm;

ll calc(int w, int k, int z, int f) {
    vector<int> v = {w,k,z,f};
    if (mm.count(v)) return mm[v];
    ll u = 0;
    if (k == 0) return 0;
    if (w < n) u = max(u,calc(w+1,k-1,z,1)+a[w+1]);
    if (w > 1 && z > 0 && f) u = max(u,calc(w-1,k-1,z-1,0)+a[w-1]);
    mm[v] = u;
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k, z;
        cin >> n >> k >> z;
        for (int i = 1; i <= n; i++) cin >> a[i];
        mm.clear();
        cout << a[1]+calc(1,k,z,1) << "\n";
    }
}