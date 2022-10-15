#include <iostream>

using namespace std;

typedef long long ll;

#define M 998244353

int n, k;
int p[202020];

ll r = 1;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i];
    int u = -1;
    ll s = 0;
    for (int i = n; i >= 1; i--) {
        if (p[i] >= n-k+1) {
            s += p[i];
            if (u != -1) {
                r *= (u-i);
                r %= M;
            }
            u = i;
        }
    }
    cout << s << " " << r << "\n";
}