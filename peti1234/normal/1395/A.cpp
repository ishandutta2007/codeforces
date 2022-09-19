#include <bits/stdc++.h>

using namespace std;
int w, a, b, c, d, e;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d, e=a%2+b%2+c%2+d%2;
        if (e<2 || (e==3 && a && b && c) || e==4) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}