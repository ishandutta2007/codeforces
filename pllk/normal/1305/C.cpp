#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[202020];
int c[1111];

int pot(int a, int b) {
    if (b == 0) return 1%m;
    int u = pot(a,b/2);
    u = (u*u)%m;
    if (b%2 == 1) u = (u*a)%m;
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    if (n > 2*m) {
        cout << "0\n";
        return 0;
    }
    int u = 1%m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[j]) {
                u = u*pot((a[i]-j+m)%m,c[j]);
                u %= m;
            }
        }
        c[a[i]%m]++;
    }
    cout << u << "\n";
}