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


std::vector<std::vector<ll> > C(2000 , std::vector<ll>());

void rek(ll i){

if(i == 0){
    C[0].push_back(1);
    return;
}else{

ll to = 1;
for(ll c = 0; c<i-1;c++){
    to*=2;
}

rek(i-1);

for(ll c = 0; c<to; c++){
    for(ll d = to; d<2*to; d++){
        C[c].push_back(C[c][d-to]);
    }
}

for(ll c = to; c<2*to; c++){
    for(ll d = 0; d<to; d++){
        C[c].push_back(C[c-to][d]);
    }
}

for(ll c = to; c<2*to; c++){
    for(ll d = to; d<2*to; d++){
        C[c].push_back(-C[c-to][d-to]);
    }
}

return;
}




}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;

    std::cin >> n;
    rek(n);

    ll to = 1;
    for(c1=0;c1<n;c1++){to*=2;}

    for(ll i = 0; i < to; i++){
        for(ll j = 0; j < to; j++){
            if(C[i][j] == 1){std::cout << "+";}
            else{std::cout << "*";}
    }std::cout << "\n";
    }

	return 0;
}