#include <bits/stdc++.h>

using namespace std;
long long w, a, b, n, x;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> n >> x;
        long long s=min(a, x/n);
        cout << (s*n+b>=x ? "YES" : "NO") << "\n";
    }
    return 0;
}