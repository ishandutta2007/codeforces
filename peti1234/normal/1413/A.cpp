#include <bits/stdc++.h>

using namespace std;
int w, n, a, b;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n/2; i++) {
            cin >> a >> b;
            cout << -b << " " << a << " ";
        }
        cout << "\n";
    }
    return 0;
}