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

    std::cin >> n;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    ll ans = 0;

    if(a <= b-c || n < b){
        ans = n/a;
    }
    else{

        d = n-b;
        e = d % (b-c);
        ans += d/(b-c)+1;
        f = b+e-(b-c);
        ans += f/a;
    }

    std::cout << ans << "\n";

	return 0;
}