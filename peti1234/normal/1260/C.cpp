#include <bits/stdc++.h>

using namespace std;
int w, a, b, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b >> k;
        int s=__gcd(a, b);
        a/=s, b/=s;
        if (a>b) {
            swap(a, b);
        }
        if ((b-2)/a+1>=k) {
            cout << "REBEL\n";
        } else {
            cout << "OBEY\n";
        }
    }
    return 0;
}