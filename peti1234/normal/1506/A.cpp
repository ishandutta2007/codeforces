#include <bits/stdc++.h>

using namespace std;
long long w, n, m, p, s, o;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> p;
        p--;
        s=p%n, o=p/n;
        cout << s*m+o+1 << "\n";

    }
    return 0;
}