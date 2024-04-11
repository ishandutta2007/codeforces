#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int m = 0;

    if (a*b*c > m)
        m = a*b*c;
    if (a * b + c > m)
        m = (a*b)+c;
    if (a + b * c > m)
        m = a + b * c;
    if ((a + b) * c > m)
        m = (a + b) * c;
    if (a * (b + c) > m)
        m = a * (b + c);
    if (a + b + c > m)
        m = a + b + c;
    cout << m;
    return 0;
}