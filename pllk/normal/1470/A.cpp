#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int k[303030];
int c[303030];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> k[i];
        sort(k,k+n);
        reverse(k,k+n);
        for (int i = 1; i <= m; i++) cin >> c[i];
        int j = 1;
        ll r = 0;
        for (int i = 0; i < n; i++) {
            if (j <= m && c[j] < c[k[i]]) {
                r += c[j];
                j++;
            } else {
                r += c[k[i]];
            }
        }
        cout << r << "\n";
    }
}