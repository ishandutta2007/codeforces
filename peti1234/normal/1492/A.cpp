#include <bits/stdc++.h>

using namespace std;
long long w, p, a, b, c;
long long ch(long long x) {
    return (x-p%x)%x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> p >> a >> b >> c;
        cout << min({ch(a), ch(b), ch(c)}) << "\n";
    }
    return 0;
}