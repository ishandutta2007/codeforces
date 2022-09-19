#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, n, k, a, b;
    cin >> w;
    while (w--) {
        cin >> k >> n >> a >> b;
        k-=n*b;
        if (k<=0) cout << -1 << "\n";
        else cout << min(n, (k-1)/(a-b)) << "\n";
    }
    return 0;
}