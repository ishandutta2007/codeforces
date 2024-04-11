#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,q,k;
ll T;

ll p;

std::vector<ll> L;
std::vector<ll> R;


int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n >> p;
    ld ans = 0.0;

    for(c1=0;c1<n;c1++){
        std::cin >> a >> b;
        L.push_back(a);
        R.push_back(b);
    }
    ll n1,n2,d1,d2;
    ld a1;
    for(c1=0;c1<n;c1++){
        c2 = (c1+1)%n;
        d1 = R[c1]-L[c1]+1;
        d2 = R[c2]-L[c2]+1;
        n1 = R[c1]/p - (L[c1]-1)/p;
        n2 = R[c2]/p - (L[c2]-1)/p;
        a = d1*n2+d2*n1-n1*n2;
        a1 = ld(a)/ld(d1*d2);
        ans += a1*2000;
    }
    std::cout << setprecision(18) <<  ans << "\n";
	return 0;
}