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

std::vector<ll> A;
int main()
{

    ll m,x,y,z,c;
    ll c1,c2,c3,c4,c5,c6;
    ll n;
    ll a,b,d,e,f;
    std::cin >> n >> m;
    for(c1=0;c1<n;c1++)
    {

        std::cin >> a;
        A.push_back(a);

    }

    std::sort(A.begin(),A.end());
    ll curr = 0;
    ll ans = 0;
    for(c1=n-1;c1>=0;c1--){
        curr += A[c1];
        if(curr >= m){ans = n-c1;break;}
    }
    if(m == 0)
    {
        ans = 0;
    }
    std::cout << ans << "\n";
	return 0;
}