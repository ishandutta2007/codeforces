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
        cout << n << " ";
        for (int i=1; i<n; i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}