#include <iostream>

using namespace std;

int n;
int z[202020];
int c;

int main() {
    cin >> n;
    z[100000] = 1;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        u += 100000;
        if (z[u]) continue;
        z[u] = 1;
        c++;
    }
    cout << c << "\n";
}