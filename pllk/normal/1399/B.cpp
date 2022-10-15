#include <iostream>

using namespace std;

int n;
int a[55];
int b[55];

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        int pa = a[1];
        int pb = b[1];
        for (int i = 1; i <= n; i++) {
            pa = min(pa,a[i]);
            pb = min(pb,b[i]);
        }
        ll r = 0;
        for (int i = 1; i <= n; i++) {
            int e = min(a[i]-pa,b[i]-pb);
            a[i] -= e; b[i] -= e;
            r += e;
            r += a[i]-pa;
            r += b[i]-pb;
        }
        cout << r << "\n";
    }
}