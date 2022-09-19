#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x, x=abs(x);
            if (i%2) x*=-1;
            cout << -x << " ";
        }
        cout << "\n";
    }
    return 0;
}