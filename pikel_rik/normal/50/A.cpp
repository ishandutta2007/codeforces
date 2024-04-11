#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    int m1, m2;

    m1 = (m / 2) * n;
    m2 = (n / 2) * m;
    
    if (m % 2 != 0)
        m1 += (n / 2);
    if (n % 2 != 0)
        m2 += (m / 2);
    
    cout << max(m1, m2);
}