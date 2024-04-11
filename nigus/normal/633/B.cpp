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
std::vector<ll> A;

ll n5(ll x){
if(x % 5 == 0){return 1+n5(x/5);}
return 0;
}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    std::cin >> m;
    ll ans = 0;
    ll nu = 0;
    for(c1=1;c1<1000000;c1++){
        nu += n5(c1);
        if(nu == m){ans++;A.push_back(c1);}

    }
std::cout << ans << "\n";
for(c1=0;c1<ans;c1++){
    std::cout << A[c1] << " ";
}
	return 0;
}