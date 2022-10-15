#include <iostream>

using namespace std;

int n, m;
int a1, b1, a2, b2;

int main() {
    b1 = 1111111111;
    b2 = 1111111111;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > a1) a1 = a;
        if (b < b1) b1 = b;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > a2) a2 = a;
        if (b < b2) b2 = b;
    }
    int u = max(a1-b2,a2-b1);
    if (u < 0) u = 0;
    cout << u << "\n";
}