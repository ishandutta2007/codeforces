#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int w, a, b, xo[c];
int main()
{
    for (int i=1; i<c; i++) {
        xo[i]=xo[i-1]^i;
    }
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        if (xo[a-1]==b) {
            cout << a << "\n";
        } else if ((xo[a-1]^b)!=a) {
            cout << a+1 << "\n";
        } else {
            cout << a+2 << "\n";
        }
    }
    return 0;
}