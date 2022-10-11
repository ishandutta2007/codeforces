#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    vector<ll> A = {a,b,c};
    sort(A.begin(),A.end());

    cout << max(0LL, d -(A[1] - A[0])) + max(0LL, d - (A[2] - A[1]));
}