#include <iostream>

using namespace std;

int n, k;
int c[1111];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    int u = 0;
    int s = 0;
    for (int i = 1; i <= k; i++) {
        u += 2*(c[i]/2);
        s += c[i]%2;
    }
    if (s%2 == 1) {u++; s--;}
    u += s/2;
    cout << u << "\n";
}