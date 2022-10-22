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

ll l;
std::vector<ll> A;
std::vector<ll> B;


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    int a,b,c;

    ll p,q;

    std::cin >> l;

    for(c1=0;c1<l;c1++)
    {
        std::cin >> a;
        A.push_back(a);
    }
    B.push_back(A[0]);
    ll ans = 0;
    ll temp=0;
   for(c2=1;c2<l-1;c2++)
   {

       b = A[c2-1] * 4 + A[c2]*2 + A[c2+1];

       if(b == 3 || b==6 || b==7)
       {
            B.push_back(1);
       }

       if(b == 0 || b==1 || b==4)
       {
            B.push_back(0);
       }

       if(b == 2 || b == 5)
       {

           if(b==2){p=0;}else{p=1;}
           temp=0;
           c3=c2;
           while((b == 2 || b == 5) && c3!=l-1)
           {

                c3++;
                b = A[c3-1] * 4 + A[c3]*2 + A[c3+1];

           }
           //std::cout << c3 << " " << A[c3] << "\n";
           q=A[c3];


           for(c4=c2;c4<(c3+c2)/2;c4++){

            B.push_back(p);

           }
           for(c4=(c3+c2)/2;c4<c3;c4++){

            B.push_back(q);

           }

           temp = (c3-c2+1)/2;
           if(temp > ans){ans = temp;}c2=c3-1;

       }


   }

    B.push_back(A[l-1]);
    std::cout << ans << "\n";
    for(c1=0;c1<l;c1++)
    {

        std::cout << B[c1] << " ";

    }

    return 0;
}