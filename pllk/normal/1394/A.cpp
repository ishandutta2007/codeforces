#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, d;
ll m;

ll a[101010];
ll b[101010];

int main() {
    cin >> n >> d >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int k = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= m) k = i;
    }
    reverse(a+1,a+k+1);
    int f = n;
    for (int i = n; i >= 1; i--) {
        b[i] = b[i+1];
        if (i%(d+1) == n%(d+1)) b[i] += a[f--];
    }
    ll u = 0;
    ll s = b[1];
    for (int i = 1; i <= n; i++) {
        if (a[i] > m) break;
        u += a[i];
        s = max(s,u+b[i+1]);
    }
    cout << s << "\n";
}