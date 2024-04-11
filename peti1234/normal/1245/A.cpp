#include <bits/stdc++.h>

using namespace std;
int w, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        cout << (__gcd(a, b)==1 ? "Finite" : "Infinite") << "\n";
    }
    return 0;
}