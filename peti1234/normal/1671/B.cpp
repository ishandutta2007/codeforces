#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, a, b;
        cin >> n >> a;
        b=a;
        for (int i=1; i<n; i++) {
            cin >> b;
        }
        cout << (b-a<=n+1 ? "YES" : "NO") << "\n";
    }
    return 0;
}