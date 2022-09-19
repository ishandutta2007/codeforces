#include <bits/stdc++.h>

using namespace std;
long long w, x, xx, sum;
bool ch(long long x) {
    long long xx=x, sum=0;
    while (xx) {
        sum+=(xx%10);
        xx/=10;
    }
    return(__gcd(x, sum)>1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> x;
        while (!ch(x)) {
            x++;
        }
        cout << x << "\n";

    }
    return 0;
}