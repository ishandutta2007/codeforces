#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long w, n, a, b;
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        if (2*a<=b) cout << n*a << "\n";
        else cout << (n/2)*b+(n%2)*a << "\n";
    }
    return 0;
}