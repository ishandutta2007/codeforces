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
ll big = 1000000007ll;

ll bort(ll x)
{
    ll x2=x;
    while(x2%2 == 0)
    {
        x2 = round(x2/2);
    }

    while(x2%3 == 0)
    {
        x2 = round(x2/3);
    }

    return x2;


}


int main()
{

    ll m,x,y,z,b,c;
    int n,a;
    ll c1,c2,c3,c4,c5,c6;
    std::vector<ll> A;
    //std::cin >>n;
    scanf("%d",&n);

    bool fail =0;
    for(c1=0;c1<n;c1++)
    {
        scanf("%d",&a);
        A.push_back(a);
        if(c1==0){m=bort(a);}
        else{if(bort(a) != m){fail=1;}}

    }

    if(fail==0){printf("Yes\n");}
    else{printf("No\n");}

	return 0;
}