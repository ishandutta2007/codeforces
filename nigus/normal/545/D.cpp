#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ll n,a,b,y,ans;
    int c1,c2,c3,c4;
    std::vector<ll> x;
    std::cin >> n;
    for(c1=0;c1<n;c1++){

        std::cin >> a;
        x.push_back(a);

    }
    std::sort(x.begin(),x.end());
    b=0;
    ans=0;
    for(c1=0;c1<n;c1++){

        if(b<=x[c1]){ans++;b+=x[c1];}



    }
    std::cout << ans << "\n";

   return 0;
}