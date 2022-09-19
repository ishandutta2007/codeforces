#include <bits/stdc++.h>

using namespace std;
long long a, b, c;
int main()
{
    cin >> a >> b, c=(b-a)/2;
    if (a>b || (b-a)%2) cout << -1;
    else if (!b) cout << 0;
    else if (a==b) cout << 1 << "\n" << a;
    else if ((a&c)==0) cout << 2 << "\n" << a+c << " " << c;
    else cout << 3 << "\n" << a << " " << c << " " << c;
    return 0;
}