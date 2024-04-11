#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=2; i<n-1; i+=2) {
            cout << i << " " << i-1 << " ";
        }
        if (n%2) {
            cout << n << " " << n-2 << " " << n-1 << "\n";
        } else {
            cout << n << " " << n-1 << "\n";
        }
    }
    return 0;
}