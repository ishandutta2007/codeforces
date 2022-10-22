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
ll n,m,k,q;
ll T;

std::vector<ll> A;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll ans = 0;
    ll L;
    std::cin >> d >> L >> a >> b;
    n = (a+b);
    ld an = ld(L-d)/ld(a+b);
    if(an<0){an = 0;}
    std::cout << setprecision(18) << an << "\n";


	return 0;
}