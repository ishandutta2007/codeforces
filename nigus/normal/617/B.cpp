#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll n,m;

std::vector<ll> A;
std::vector<ll> DP;

ll nn;

int main()
{
    ll c1,c2,c3;
    ll a,b,c,d;

    std::cin >> n;
    ll ans = 1;
    nn = 0;
    for(c1 = 0; c1 < n; c1++){
        std::cin >> a;
        A.push_back(a);
        if(a  == 1){
            nn++;
        }
    }
    if(nn == 0){
        std::cout << 0 << "\n";
    }
    if(nn == 1){

        std::cout << 1 << "\n";
    }
    if(nn > 1){
        bool fail = 1;
        ll mul = 1;
        ans = 1;
        for(c1 = 0 ; c1< n; c1++){
            if(A[c1] == 1){fail = 0;  ans *= mul;mul = 1;}
            if(A[c1] == 0 && fail == 0){mul++;}
        }
        std::cout << ans << "\n";

    }




    return 0;
}