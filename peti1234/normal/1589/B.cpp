#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, a, b;
    cin >> w;
    while (w--) {
        cin >> a >> b;
        cout << (a*b+2)/3 << "\n";
    }
    return 0;
}