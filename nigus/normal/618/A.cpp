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
ll n,m;

ll to(ll i){

ll ans = 0;
ll a = 1;
while(2*a <= i){
    a *= 2;
    ans ++;
}
return ans;
}

ll two(ll i){
ll a = 1;
for(ll c = 0; c < i; c++){
    a *= 2;
}
return a;
}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;

    std::cin >> n;

    ll ans = 0;
    m = n;

    while(m >= 1){

        cout << to(m)+1 << " ";
        m -= two(to(m));



    }

	return 0;
}