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
    ll n;

    std::vector<ll> prim;

    ll np;
    np=0;
    for(c1=2;c1<1001;c1++)
    {

        for(c2=2;c2<=c1;c2++)
        {

            if(c1%c2==0)
            {
                if(c1==c2){prim.push_back(c1);np++;}
                break;
            }


        }

    }



    std::cin >> n;


    std::vector<ll> A;
    ll ans = 0;

    for(c1=0;c1<np;c1++)
    {

        T=prim[c1];
        while(T<=n)
        {

            A.push_back(T);
            ans++;
            T*=prim[c1];

        }

    }

    std::cout << ans << "\n";
    for(c1=0;c1<ans-1;c1++)
    {

        std::cout << A[c1] << " ";

    }
    if(n>1){std::cout << A[ans-1] << "\n";}

    return 0;
}