#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                cout << (j==1 || j==i) << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}