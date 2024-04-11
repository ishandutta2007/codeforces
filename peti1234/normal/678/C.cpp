#include <bits/stdc++.h>

using namespace std;
long long n, a, b, p, q, s;
int main()
{
    cin >> n >> a >> b >> p >> q;
    s=a*b/__gcd(a, b);
    cout << (n/a-n/s)*p+(n/b-n/s)*q+(n/s)*max(p, q) << "\n";
    return 0;
}