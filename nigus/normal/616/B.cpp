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
ll big = 1000000007ll;
ll n,m,q,k;
std::vector<std::vector<ll> > C(100000 , std::vector<ll>());

int main()
{
    ll a,b,c;
    ll c1,c2,c3,c4,c5;
    ll t;
    std::cin >> a >> b;
    ll ma = 0;
    ll mi;
    for(c1 = 0; c1<a; c1++){
            mi = 99999999999999ll;
        for(c2 = 0; c2<b; c2++){
                std::cin >> c;
            if(c<mi){mi=c;}

        }
        if(mi>ma){ma=mi;}
    }
std::cout << ma << "\n";



return 0;
}