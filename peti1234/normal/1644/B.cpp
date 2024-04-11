#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        if (n==3) {
            cout << "3 1 2\n3 2 1\n2 3 1\n";
        } else {
            for (int i=1; i<=n; i++) {
                for (int j=i; j>=1; j--) cout << j << " ";
                for (int j=n; j>i; j--) cout << j << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}