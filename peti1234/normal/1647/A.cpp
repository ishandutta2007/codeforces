#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        while (n) {
            if (n%3==1) {
                cout << 1;
                n--;
            } else {
                cout << 2;
                n-=2;
                if (n) {
                    cout << 1;
                    n--;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}