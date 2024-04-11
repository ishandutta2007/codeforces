#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a==d && (a!=0 || c==0)) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}