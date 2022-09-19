#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        for (int i=n; i<2*n; i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}