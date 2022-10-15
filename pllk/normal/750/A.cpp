#include <iostream>

using namespace std;

int n, k;
int u, c;

int main() {
    cin >> n >> k;
    u = 4*60-k;
    for (int i = 1; i <= n; i++) {
        if (u < 5*i) break;
        c++;
        u -= 5*i;
    }
    cout << c << "\n";
}