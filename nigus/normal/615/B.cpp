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

std::vector<ll> deg;
std::vector<std::vector<ll> > C(400000 , std::vector<ll>());
std::vector<ll> TL;

ll dp(ll i){

if(TL[i] != -1){return TL[i];}
ll a = 0;
ll b,c,d;
d = 0;
for(c = 0; c<deg[i]; c++){
    b = C[i][c];
    if(b < i){
        d = max(dp(b),d);
    }

}
TL[i] = 1+d;
return 1+d;

}

int main()
{
	ll  z,a,b,c,x,y,l;
	ll c1,c2,c3,c4,c5;
    ll ans;

	std::cin >> n >> m;
	for(c1=0;c1<n;c1++){

        deg.push_back(0);
        TL.push_back(-1);

	}

	for(c1=0;c1<m;c1++)
	{

	    std::cin >> a >> b;
	    a--;
	    b--;

	    deg[a]++;
	    deg[b]++;
	    C[a].push_back(b);
        C[b].push_back(a);

	}
	ans = 0;
	for(c1=0;c1<n;c1++){
        a=dp(c1);
        if(a*deg[c1] > ans){ans = a*deg[c1];}
        //std::cout << a << "\n";
	}
	std::cout << ans << "\n";

	return 0;
}