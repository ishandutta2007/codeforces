#include <bits/stdc++.h>

using namespace std;
long long n, a, b, c;
int main()
{
    cin >> n >> a >> b >> c;
    if (n%4==0) {
        cout << 0;
    }
    if (n%4==1) {
        cout << min({c, a+b, 3*a});
    }
    if (n%4==2) {
        cout << min({b, 2*a, 2*c});
    }
    if (n%4==3) {
        cout << min({a, b+c, 3*c});
    }
    cout << "\n";
    return 0;
}