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
ll n,m,k,q,d;
ll T;



int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n >> a >> b;

    if(a*b < n){std::cout << -1 << "\n";}

    else{
        c3 = 0;
        for(c1 = 0; c1 < a; c1++){
            if(b % 2 == 0 && c1 % 2 == 1){
                for(c2 = b-1; c2 >= 0; c2--){
                    c3 = c1*b+c2;
                if(c3 < n){std::cout << c3+1 << " ";}
                else{std::cout << 0 << " ";}
            }
            }
            else{
            for(c2 = 0; c2 < b; c2++){
                    c3 = c1*b+c2;
                if(c3 < n){std::cout << c3+1 << " ";}
                else{std::cout << 0 << " ";}

            }
            }
            std::cout << "\n";
        }

    }


	return 0;
}