#include <iostream>

using namespace std;

int n;
int d[101010];

int main() {
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        d[a]++; d[b]++;
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 2) ok = false;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}