#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[111], b[111];
int v[111];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[j]) continue;
            if (abs(a[i]-b[j]) > 1) continue;
            c++;
            v[j] = 1;
            break;
        }
    }
    cout << c << "\n";
}