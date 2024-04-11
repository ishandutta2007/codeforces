#include <bits/stdc++.h>

using namespace std;
int n;
long double a, b, x, y, t, mini=2e9;
int main()
{
    cin >> a >> b >> n;
    while (n--) {
        cin >> x >> y >> t;
        x-=a, y-=b;
        mini=min(mini, sqrt(x*x+y*y)/t);
    }
    cout.precision(20);
    cout << mini << endl;
    return 0;
}