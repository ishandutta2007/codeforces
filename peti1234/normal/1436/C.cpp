#include <bits/stdc++.h>

using namespace std;
long long mod=1e9+7;
long long n, a, b, c, x, pos, sum=1, kis, nagy;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> pos, b=n, kis=x-1, nagy=n-x;
    while(b>a) {
        c=(a+b)/2;
        if (c==pos) a=c+1;
        if (c<pos) sum*=kis, kis--, a=c+1;
        if (c>pos) sum*=nagy, nagy--, b=c;
        sum%=mod;
    }
    for (int i=1; i<=kis+nagy; i++) sum*=i, sum%=mod;
    cout << sum << "\n";
    return 0;
}