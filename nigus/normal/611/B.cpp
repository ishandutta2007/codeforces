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
ll n,m,k;

ll tl(ll i){

ll ans = 0ll;
ll to = 1ll;
while(to <= i){to *= 2; ans++;}
return ans;
}

ll fn(ll i){
ll ans = 0ll;
ll nu = 0ll;
ll i2 = i;
ll c = 0ll;
while(nu < 65){
    c++;
    if(i2 % 2 == 1){
        ans = nu;
        i2--;
    }
    else{
        nu = c;
    }
    i2/=2;
}
return ans;
}

ll nn(ll i){
ll ans = 0;
ll nu = 0;
ll i2 = i;
ll c = 0;
while(nu < 65){
    c++;
    if(i2 % 2 == 1){
        ans = nu;
        i2--;
        //cout << 1;
    }
    else{
        nu++;
        //cout << 0;
    }
    i2/=2;
}
//cout << "\n";
return ans;


}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;
    ll q;
    ll ans = 0;
    std::cin >> a >> b;
    ll tl1 = tl(a);
    ll tl2 = tl(b);
    ll fn1 = fn(a);
    ll fn2 = fn(b);
    ll nn1 = nn(a);
    ll nn2 = nn(b);

    //std::cout << "TL: " << tl1 << " " << tl2 << "\n";

    //std::cout << "FN: " << fn1 << " " << fn2 << "\n";

    //std::cout << "NN: " << nn1 << " " << nn2 << "\n";

    if(tl1 == tl2){

        ans = fn1 - fn2;
        if(nn2 == 1){ans++;}

    }

    else{

        ans += fn1;
        ll c = tl1+1;
        while(c < tl2){
            ans += c-1;
            c++;
        }
        ans += tl2 - fn2 - 1;
        if(nn2 == 1){ans++;}


    }
std::cout << ans << "\n";


	return 0;
}