#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main()
{
    ll n,k;
    cin >> n >> k;
    ll v = n/k;
    ll r = n%k;
    ll sum = 0;
    ll s = k-r;
    sum += ((v*(v-1))/2) * s;
    sum += (((v+1) * (v))/2) * r;
    ll mx = n-(k-1);
    cout << sum << " " << (mx*(mx-1))/2;
    return 0;
}