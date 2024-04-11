#include <bits/stdc++.h>

using namespace std;
long long n, r, a, b, c, d, dist, ans;
int main()
{
    cin >> r >> a >> b >> c >> d;
    dist=(a-c)*(a-c)+(b-d)*(b-d);
    while (ans*ans*4*r*r<dist) ans++;
    cout << ans << "\n";
    return 0;
}