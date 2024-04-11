#include <iostream>
#include <random>

using namespace std;

typedef long long ll;

int n, m, p;
ll t[202020];

int ppc;
ll pb;

int sum[1<<15];

void check(int k) {
    for (int i = 0; i < (1<<p); i++) sum[i] = 0;
    for (int i = 1; i <= n; i++) {
        int h = 0;
        int u = 0;
        for (int j = 0; j < m; j++) {
            if (t[k]&(1LL<<j)) {
                if (t[i]&(1LL<<j)) u |= (1<<h);
                h++;
            }
        }
        sum[u]++;
    }
    for (int h = 0; h < p; h++) {
        for (int s = 0; s < (1<<p); s++) {
            if (!(s&(1<<h))) sum[s] += sum[s^(1<<h)];
        }
    }
    int r = (n+1)/2;
    for (int i = 0; i < (1<<p); i++) {
        if (sum[i] >= r) {
            int pc = __builtin_popcount(i);
            if (pc > ppc) {
                ppc = pc;
                pb = 0;
                int g = 0;
                for (int h = 0; h < m; h++) {
                    if (t[k]&(1LL<<h)) {
                        if (i&(1<<g)) pb |= (1LL<<h);
                        g++;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        ll b = 0, k = 1;
        for (int i = 0; i < m; i++) {
            if (x[m-1-i] == '1') b |= k;
            k *= 2;
        }
        t[i] = b;
    }
    mt19937 g(random_device{}());
    uniform_int_distribution<int> d(1,n);
    for (int z = 1; z <= 20; z++) {
        check(d(g));
    }
    for (int i = m-1; i >= 0; i--) {
        if (pb&(1LL<<i)) cout << "1";
        else cout << "0";
    }
    cout << "\n";
}