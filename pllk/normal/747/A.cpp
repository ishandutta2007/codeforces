#include <iostream>

using namespace std;

int n;
int u;

int main() {
    cin >> n;
    for (int a = 1; a*a <= n; a++) {
        if (n%a != 0) continue;
        u = a;
    }
    cout << u << " " << n/u << "\n";
}