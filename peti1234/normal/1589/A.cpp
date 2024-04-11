#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, a, b;
    cin >> w;
    while (w--) {
        cin >> a >> b;
        cout << a*a << " " << -b*b << "\n";
    }
    return 0;
}