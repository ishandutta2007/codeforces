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
    std::cin >> n;
    ll sum=0;
    for(c1=0;c1<n;c1++)
    {
        std::cin >> a;
        A.push_back(a);
        sum+=a;
    }
    ll mod;
    ll med;
    med = sum/n;
    if(sum==0){std::cout << 0 <<"\n";}else{
    mod = sum - n*med;

    std::sort(A.begin(),A.end());
    ll ans = 0;
    for(c1=0;c1<n;c1++){
        if(c1<n-mod){
            ans += abs(med-A[c1]);
        }
        else{
            ans += abs(med+1-A[c1]);
        }
    }
    ans /= 2;

    std::cout << ans << "\n";}
	return 0;
}