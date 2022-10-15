#include <iostream>

using namespace std;

#define M 998244353

typedef long long ll;

int  n;
int a[1234];
ll ncr[1234][1234];
ll s[1234];
ll cc;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ncr[0][0] = 1;
    for (int i = 1; i <= 1111; i++) {
        ncr[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = ncr[i-1][j]+ncr[i-1][j-1];
            ncr[i][j] %= M;
        }
    }
    s[n+1] = 1;
    for (int i = n; i >= 1; i--) {
        s[i] = s[i+1];
        if (a[i] <= 0) continue;
        for (int j = i+1; j <= n; j++) {
            if (j-i-1 >= a[i]-1) {
                ll u = (ncr[j-i-1][a[i]-1]*s[j+1])%M;
                cc = (cc+u)%M;
                s[i] = (s[i]+u)%M;
            }
        }
    }
    cout << cc << "\n";
}