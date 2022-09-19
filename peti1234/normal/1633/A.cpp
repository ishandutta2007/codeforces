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
        if (n%7==0) {
            cout << n << "\n";
        } else {
            n=n/10*10;
            while (n%7) {
                n++;
            }
            cout << n << "\n";
        }
    }
    return 0;
}