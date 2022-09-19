#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a, b;
        cin >> a >> b;
        if (a<=2) cout << 1 << "\n";
        else {
            a-=2;
            cout << 1+(a+b-1)/b << "\n";
        }
    }
    return 0;
}