#include <bits/stdc++.h>

using namespace std;
long long a, b, c, d, e;
int main()
{
    cin >> a >> b >> c >> d >> e;
    if (b-b%e>=a && b/e>=c && d*e>=a) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}