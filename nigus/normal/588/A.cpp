#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll n,m;

std::vector<ll> A;
std::vector<ll> B;

int main()
{
    ll c1,c2,c3;
    ll a,b,c,d;

    std::cin >> n;
    ll mi = 99999999999ll;
    ll ans = 0;
    for(c1=0;c1<n;c1++){

        std::cin >> a >> b;
        if(b < mi){mi = b;}
        ans += a*mi;
    }
    std::cout << ans <<"\n";
    return 0;
}