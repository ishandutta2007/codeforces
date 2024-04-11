#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll c;
int n;
vector<ll> v;
ll s[202020];

bool lol(int x) {
    //cout << "x=" << x << "\n";
    int k = n;
    ll z = c;
    bool ok = true;
    if (x > v[k] && z >= x) {
        z -= x;
        ok = false;
    }
    while (true) {
        int u;
        if (v[k] <= z) goto s1;
        u = 0;
        for (int b = n; b >= 1; b /= 2) {
            while (k-u-b >= 1 && v[k-u-b] > z) u += b;
        }
        k = k-u-1;
        s1:
        if (k == 0 || x > v[k]) break;
        u = 0;
        for (int b = n; b >= 1; b /= 2) {
            while (k-u-b >= 1 && v[k-u-b] >= x && z >= s[k]-s[k-u-b-1]) u += b;
        }
        //cout << "p1 " << s[k]-s[k-u-1] << "\n";
        z -= s[k]-s[k-u-1];
        k = k-u-1;
        if (k == 0 || x > v[k]) break;
    }
    if (k > 0 && x > v[k] && z >= x && ok) {
        z -= x;
    }
    //cout << "! " << k << " " << v[k] << "\n";
    while (true) {
        if (k == 0) break;
        int u;
        if (v[k] <= z) goto s2;
        u = 0;
        for (int b = n; b >= 1; b /= 2) {
            while (k-u-b >= 1 && v[k-u-b] > z) u += b;
        }
        k = k-u-1;
        s2:
        if (k == 0) break;
        u = 0;
        for (int b = n; b >= 1; b /= 2) {
            while (k-u-b >= 1 && z >= s[k]-s[k-u-b-1]) u += b;
        }
        //cout << "p2 " << s[k]-s[k-u-1] << "\n";
        z -= s[k]-s[k-u-1];
        k = k-u-1;
        if (k == 0) break;
    }
    //cout << "z=" << z << "\n";
    return z > 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    v.insert(v.begin(),0);
    for (int i = 1; i <= n; i++) s[i] = s[i-1]+v[i];
    for (int i = 1; i <= c-1; i++) {
        if (lol(i)) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "Greed is good\n";
}