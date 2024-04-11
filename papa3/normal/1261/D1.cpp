#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int INF = 1000000000000000000ll;
const int mod = 998244353;

int pot(int n, int k = mod - 2) {
    int res = 1;
    while (k) {
        if (k % 2) res = res * n % mod;
        n = n * n % mod;
        k /= 2;
    }
    return res;
}

int silnia[1000010];
int odw[1000010];
int k_pot[1000010];

int dwumian(int n, int k) {
    if (k < 0) return 0;
    if (k > n) return 0;
    return silnia[n] * odw[k] % mod * odw[n - k] % mod;
}

int algo(int n, int k) {
    int res = 0;
    
    k -= 2;
    int kk = 0;
    if (k) {
        kk = pot(k);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i && i + j <= n; j++) {
            res = (res + dwumian(n, i) * dwumian(n - i, j) % mod * k_pot[n - i - j]) % mod;
        }
    }
    
    return res;
}

void init(int k) {
    silnia[0] = 1;
    odw[0] = 1;
    k_pot[0] = 1;
    for (int i = 1; i < 1000010; i++) {
        silnia[i] = silnia[i - 1] * i % mod;
        odw[i] = pot(silnia[i]);
        k_pot[i] = k_pot[i - 1] * k % mod;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    int n, k;
    cin >> n >> k;
    init(k - 2);
    vector<int> v;
    for (int a, i = 0; i < n; i++) {
        cin >> a;
        if (i == 0 || v.back() != a) v.push_back(a);
    }
    while (!v.empty() && v.back() == v.front()) v.pop_back();
    
    if (k == 1) {
        cout << 0;
        return 0;
    }
    
    int res = algo(v.size(), k) * pot(k, n - v.size()) % mod;
    cout << res;
    
    return 0;
}