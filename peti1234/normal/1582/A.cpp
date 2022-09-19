#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, a, b, c;
    cin >> w;
    while (w--) {
        cin >> a >> b >> c;
        cout << ((a+c)%2 ? 1 : 0) << "\n";
    }
    return 0;
}