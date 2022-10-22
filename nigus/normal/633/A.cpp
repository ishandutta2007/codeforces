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
ll n,m,k,q;
ll T;

ll gcd(ll a, ll b){
if(b == 0){return a;}
return gcd(b,a%b);
}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    std::cin >> a >> b >> c;

    if(c % a == 0 || c % b == 0){std::cout << "Yes\n";}
    else{
        bool fail = 1;
        while(c > 0){
            c-=a;
            if(c % b == 0 && c > 0){fail = 0;}
        }
        if(fail == 1){std::cout << "No\n";}
        else{std::cout << "Yes\n";}
    }

	return 0;
}