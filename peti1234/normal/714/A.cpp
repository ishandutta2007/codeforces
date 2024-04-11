#include <bits/stdc++.h>

using namespace std;
long long a, b, c, d, e;
int main()
{
    cin >> a >> b >> c >> d >> e;
    if (a>d) {
        cout << "0" << endl;
        return 0;
    }
    if (c>b) {
        cout << "0" << endl;
        return 0;
    }
    if (e>=a && e>=c && e<=b && e<=d) {
        cout << min (b,d) - max(a,c);

    }
    else cout << min (b,d) - max(a,c)+1 ;
    return 0;
}