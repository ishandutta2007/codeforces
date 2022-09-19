#include <bits/stdc++.h>

using namespace std;
int w, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        if ((a+b)%2) {
            cout << -1 << "\n";
        } else {
            if (a+b==0) {
                cout << 0 << "\n";
            } else {
                cout << 1+(a!=b) << "\n";
            }
        }
    }
    return 0;
}