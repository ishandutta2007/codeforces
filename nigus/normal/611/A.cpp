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
while(to < i){to *= 2; ans++;}
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
    string ch1,ch2;
    std::cin >> a >> ch1 >> ch2;

    if(ch2 == "week"){

        ll a2 = (a+2)%7;

        ans = (366-a2-1)/7;
        std::cout << ans+1 << "\n";


    }

else{

    if(a <= 29){ans = 12;}
    if(a == 30){ans = 11;}
    if(a == 31){ans = 7;}

    std::cout << ans << "\n";




}
	return 0;
}