#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n,k;
    cin >> n >> k;
    ll win = n / 2;
    ll sert = k+1;
    win -= (win % sert);
    ll dp = win / sert;
    ll s = dp * k;
    cout << dp << " " << s << " " << n - win;
    return 0;
}