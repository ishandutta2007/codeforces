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



int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n >> m;

    x = 10000000ll;
    bool fail = 1;
    ll m2,n2;
    for(c1 = x; c1 > 0; c1--){
        m2 = m; n2 = n;
        a = c1/2;
        b = c1/3;
        c = c1/6;

        m2 = max(m2-b+c,0ll);
        n2 = max(n2-a+c,0ll);
        if((n2+m2 > c)){std::cout << c1+1 << "\n";break;}
    }

	return 0;
}