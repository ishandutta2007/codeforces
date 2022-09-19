#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, n, k;
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            char c='a'+(i%k);
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}