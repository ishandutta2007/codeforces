#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        if (n%2) {
            cout << 7;
            n-=3;
        }
        while (n>=2) {
            cout << 1;
            n-=2;
        }
        cout << "\n";
    }
    return 0;
}