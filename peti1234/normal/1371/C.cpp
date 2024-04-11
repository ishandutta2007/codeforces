#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        if (m>min(a, b) || m+n>a+b) cout << "No\n";
        else cout << "Yes\n";

    }
    return 0;
}