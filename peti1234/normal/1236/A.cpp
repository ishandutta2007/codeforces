#include <bits/stdc++.h>

using namespace std;
int w, a, b, c;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> c;
        int s=min(b, c/2);
        cout << 3*(s+min(a, (b-s)/2)) << "\n";
    }
    return 0;
}