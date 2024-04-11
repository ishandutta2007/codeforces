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
    ll n,a,b,y;
    int c1,c2,c3,c4;
    int ans;
    std::vector<ll> x;
    std::vector<ll> h;
    std::cin >> n;
    for(c1=0;c1<n;c1++){
        std::cin >> a;
        std::cin >> b;
        x.push_back(a);
        h.push_back(b);
    }
    ans=1;
    y=x[0];
    for(c1=1;c1<n;c1++){

        if(x[c1]-y > h[c1]){y=x[c1];ans++;}
        else{
            if(c1+1==n){ans++;}
            else{
                if(x[c1+1]-x[c1] > h[c1]){y=x[c1] + h[c1]; ans++;}
                    else{y=x[c1];}


            }
        }

    }
    std::cout << ans << "\n";

   return 0;
}