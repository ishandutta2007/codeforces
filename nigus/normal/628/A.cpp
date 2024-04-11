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


int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll p;
    std::cin >> n >> b >> p;
    ll a1,a2;
    a2  = n*p;
    a1 = 0;
    while(n > 1){
        k = 1;
        while(2*k <= n){
            k *= 2;
        }

        a1 += (2*b+1)*k/2;
        n -= k/2;
    }
    std::cout << a1 << " " << a2 << "\n";

	return 0;
}