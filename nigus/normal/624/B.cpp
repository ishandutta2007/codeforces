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

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll ans = 0;
    std::cin >> n;
    for(c1=0;c1<n;c1++){
        std::cin >> a;
        A.push_back(a);
    }
    std::sort(A.begin(),A.end());
    ll nu = 9999999999ll;
    for(c1 = n-1;c1>=0;c1--){
        if(A[c1] < nu){nu = A[c1];ans += nu;}
        else{
            if(nu > 0){nu--;ans+=nu;}
        }
    }
    std::cout << ans << "\n";
	return 0;
}