#include <bits/stdc++.h>
using namespace std;

int main()
{
    typedef long long ll;
    ll n, m;
    cin >> n >> m;
    ll mok = n/m;
    ll nam = n%m;
    ll mv = (mok+1)*(mok)/2*nam + (m-nam)*mok*(mok-1)/2;
    ll Mv = (n-m+1)*(n-m)/2;
    cout << mv << ' ' << Mv;
    return 0;
}