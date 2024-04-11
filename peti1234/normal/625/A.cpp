#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    if (a<=b-c) {
        cout << n/a;
        return 0;
    }

    long long osszeg=0;
    if (n<min (a, b)) {
        cout << 0;
        return 0;
    }

    if (n>=b) {
    osszeg+=(n-b)/(b-c)+1;
    n-=osszeg*(b-c);
}

    osszeg+=n/a;
    cout << osszeg;
    return 0;
}