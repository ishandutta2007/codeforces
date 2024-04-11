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
ll n,m,q,k;
ll T;

std::vector<ll> A;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n;
    b = 0;
    for(c1=0;c1<n;c1++){
        std::cin >> a;
        A.push_back(a);
        b+=a;
    }
    std::sort(A.begin(),A.end());
    if(b % 2 == 0){
        std::cout << b << "\n";
    }
    else{
        a = A[0];
        c = 0;
        while(a%2 == 0){
            c++;
            a = A[c];
        }
        std::cout << b-a <<  "\n";
    }


	return 0;
}