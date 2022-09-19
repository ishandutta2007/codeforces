#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n;
        if (n<4) {
            cout << n-1 << "\n";
        } else {
            cout << n%2+2 << "\n";
        }
    }
    return 0;
}