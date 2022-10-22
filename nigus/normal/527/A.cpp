#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <set>


using namespace std;
typedef long long ll;


ll rek(ll m,ll n){

if(m==n){return 1ll;}
else{
    if(m==0 || n==0){return 0l;}

    ll k,l;
    k=rek(n,m%n);
    l=ll(m/n);
    return (l + k);

}


}


int main()
{

   ll c1,c2,c3,c4,c5,c6,c7;
   ll x;
   ll a,b;

    std::cin >> a;
    std::cin >> b;

    c1=rek(a,b);
    std::cout << c1 << "\n";




    return 0;
}