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

ll n, h , w;
ll m;
ll upp(ll a , ll p){
ll d;
if(p == 0){return 1ll;}
if(p%2==0){
    ll b = upp(a,p/2);
    return (b*b)%big;
}

else{

    ll b = upp(a,p/2);
    d = (b*b)%big;
    return (d*a)%big;

}

}

int main()
{
	ll  z,a,b,c,x,y,l;
	ll c1,c2,c3,c4,c5;
    ll ans;
	std::vector<ll> K;
    std::cin >> m;
    for(c1=0;c1<200001;c1++){
        K.push_back(0);
    }
    for(c1=0;c1<m;c1++){

        std::cin >> a;
        K[a]++;

    }
    ans = 1;
    ll tinv = upp(2,big-3);
    ll k = 1ll;
    bool sq = 1;
    for(c1=0;c1<200001;c1++){
        if(K[c1] % 2 == 1 && sq == 1){
            a = (K[c1]+1)/2;
            sq = 0;
        }else{a=(K[c1]+1);}
        k *= a;
        k %= (big-1);

    }
    ll d,e;
    for(c1=0;c1<200001;c1++){
        if(K[c1] != 0){

            d = K[c1]*k;
            if(sq == 1){d /= 2;}
            d %= (big-1);
            ans *= upp(c1,d);
            ans %= big;

        }
    }
    std::cout << ans << "\n";
	return 0;
}