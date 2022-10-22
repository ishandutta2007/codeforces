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
ll n,m,k,q,d,h;
//ll T;


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   std::cin >> n >> d >> h;

    if(d == h){
        if(d == 1){
        if(n != 2){std::cout << -1 << "\n";}
        else{
            std::cout << "1 2\n";
        }
        }
        else{

            if(d+1 > n){std::cout << -1 << "\n";}
            else{

                for(c1 = 0; c1 < h;c1++){
                    std::cout << c1+1 << " " << c1+2 << "\n";
                }
                for(c1 = h; c1 < n-1; c1++){
                    std::cout << "2 " << c1+2 << "\n";
                }

            }


        }
    }

    else{


        if(d < h || d+1 > n || d-h > h){std::cout << -1 << "\n";}
        else{

            for(c1 = 0; c1 < h; c1++){
                std::cout << c1+1 << " " << c1+2 << "\n";
            }
            std::cout << "1 " << h+2 << "\n";
            for(c1 = h+2; c1 <= d; c1++){
                std::cout << c1 << " " << c1+1 << "\n";
            }
            for(c1 = d+2; c1 <= n; c1++){

                std::cout << "1 " << c1 << "\n";

            }


        }




    }



	return 0;
}