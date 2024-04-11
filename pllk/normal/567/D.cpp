#include <iostream>

using namespace std;

int n, k, a;
int m;
int q[202020];
int t[202020];

bool ok(int x) {
    for (int i = 1; i <= n; i++) t[i] = 0;
    t[n+1] = 1;
    for (int i = 1; i <= x; i++) t[q[i]] = 1;
    int c = 0, z = 0;
    for (int i = 1; i <= n+1; i++) {
        if (t[i]) {
            if (z >= a) {
	        z -= a;
        	c++;
	        c += z/(a+1);
            }
            z = 0;
        } else {
            z++;
        }
    }
    return k <= c;
}

int main() {
    cin >> n >> k >> a;
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> q[i];
    int u = -1;
    for (int b = m; b >= 1; b /= 2) {
        while (u+b <= m && ok(u+b)) u += b;
    }
    u++;
    if (u == m+1) cout << -1 << "\n";
    else cout << u << "\n";
}