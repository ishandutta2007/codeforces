#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a, b, c, d, x=0;
        cin >> a >> b >> c >> d;
        if (a!=c && b!=d) {
            x=2;
        }
        cout << x+abs(a-c)+abs(b-d) << "\n";
    }
    return 0;
}