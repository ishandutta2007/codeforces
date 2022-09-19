#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        if (n==1) {
            cout << -1 << "\n";
            continue;
        }
        n-=2;
        for (int i=1; i<=n; i++) cout << 6;
        cout << 4 << 3 << "\n";
    }
    return 0;
}