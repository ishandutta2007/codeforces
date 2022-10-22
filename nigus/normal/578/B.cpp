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

using namespace std;
typedef long long ll;

ll big = 1000000007ll;
ll bp = 1168195727ll;



int main()
{
    ll c1,c2,c3,c4,c5,c6;

    ll T;
    ll a,b;
    ll n;
    ll x,y,z,w,k;

    std::cin >> n >> k >> x;

    std::vector<ll> CS1;
    std::vector<ll> CS2;
    std::vector<ll> A;

for(c1=0;c1<n;c1++)
{

    std::cin >> a;
    A.push_back(a);

}

ll x2=1;
for(c1=0;c1<k;c1++)
{
    x2*=x;

}

ll nu=0;
CS1.push_back(nu);
for(c1=0;c1<n-1;c1++)
{
    nu=CS1[c1]|A[c1];
    CS1.push_back(nu);


}


nu=0;
CS2.push_back(nu);
for(c1=n-1;c1>0;c1--)
{
    nu=CS2[n-1-c1]|A[c1];
    CS2.push_back(nu);

}

ll ans=0;

for(c1=0;c1<n;c1++)
{

    nu=(A[c1]*x2)|CS1[c1]|CS2[n-1-c1];
    if(nu>ans){ans=nu;}



}

std::cout << ans << "\n";




    return 0;
}