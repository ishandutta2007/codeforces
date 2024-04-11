#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, n, k;
    cin >> w;
    while (w--) {
        cin >> n >> k;
        if (k%4==0) cout << "NO\n";
        else {
            cout << "YES\n";
            if (k%2) {
                for (int i=1; i<n; i+=2) {
                    cout << i << " " << i+1 << "\n";
                }
            } else {
                for (int i=1; i<n; i+=2) {
                    if (i%4==1) cout << i+1 << " " << i << "\n";
                    else cout << i << " " << i+1 << "\n";
                }
            }
        }
    }
    return 0;
}