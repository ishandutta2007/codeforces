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

ll f(ll x, ll s){
    ll a = x%2;
    ll b = s%2;
    if(s<0){return 0;}
    if(x == 0 && s == 0){return 1;}
    if(a == b){
            if(a == 0){
                return (f(x/2,s/2) + f(x/2,s/2-1));
            }
            return ll(2)*f(x/2,s/2);
    }
    else{return 0;}
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,d,e;
    ll s;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   std::cin >> s >> x;
   ll ans = f(x,s);
   if(s==x){ans-=2;}
   std::cout << ans << "\n";
	return 0;
}