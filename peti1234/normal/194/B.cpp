#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long w, x;
    cin >> w;
    while (w--) {
        cin >> x;
        cout << 1+4*x/__gcd(4*x, x+1) << "\n";
    }
    return 0;
}