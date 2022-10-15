#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define M 1000000007

ll pot(int a, int b) {
    if (b == 0) return 1;
    ll u = pot(a,b/2);
    u = u*u%M;
    if (b%2 == 1) u = u*a%M;
    return u;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        int c = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            for (int j = 0; j < m; j++) {
                if (v[i][j] == '#') c++;
            }
        }
        ll r = pot(2,c);
        if (n*m == c) r--;
        if (r < 0) r += M;
        cout << r << "\n";
    }
}