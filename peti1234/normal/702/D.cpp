#include <bits/stdc++.h>

using namespace std;
long long d, k, a, b, t, ans;
int main()
{
    cin >> d >> k >> a >> b >> t;
    if (k>=d) {
        cout << d*a << endl;
        return 0;
    }
    ans=k*a;
    d-=k;
    cout << ans+d/k*min(k*a+t, k*b)+min(d%k*a+t, d%k*b) << "\n";
    return 0;
}