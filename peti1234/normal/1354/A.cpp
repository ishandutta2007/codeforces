#include <bits/stdc++.h>

using namespace std;
long long w, a, b, c, d;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d;
        if (a<=b) cout << b;
        else if (d>=c) cout << -1;
        else cout << b+c*((a-b+c-d-1)/(c-d));
        cout << "\n";
    }
    return 0;
}