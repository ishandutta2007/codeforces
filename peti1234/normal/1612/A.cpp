#include <bits/stdc++.h>

using namespace std;
int w, a, b;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b;
        if ((a+b)%2) cout << "-1 -1\n";
        else cout << (a+1)/2 << " " << b/2 << "\n";
    }
    return 0;
}