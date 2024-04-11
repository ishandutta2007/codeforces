#include <bits/stdc++.h>

using namespace std;
long long k, n, ans=1;
int main()
{
    cin >> k;
    n+=k%10*100, k/=10;
    n+=k%10*10, k/=10;
    n+=k%10*1000, k/=10;
    n+=k%10, k/=10;
    n+=k%10*10000, k/=10;
    for (int i=1; i<=5; i++) {
        ans*=n;
        ans%=100000;
    }
    if (ans<10000) cout << 0;
    if (ans<1000) cout << 0;
    if (ans<100) cout << 0;
    if (ans<10) cout << 0;
    if (ans<1) cout << 0;
    else cout << ans;
    return 0;
}