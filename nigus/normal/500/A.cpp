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
ll n,m,k;

std::vector<ll> A;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;
    ll t;
    std::cin >> n >> t;
    t--;
    for(c1=0;c1<n-1;c1++){
        std::cin>>a;
        A.push_back(a);
    }
    bool fail = 1;
    c1=0;
    while(c1 != n-1){

        c1 = A[c1]+c1;
        if(c1==t){fail=0;}

    }
if(fail==1){std::cout << "NO\n";}
else{std::cout << "YES\n";}

	return 0;
}