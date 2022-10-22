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
ll n,m;


int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,c,d,e,f;
    ll x,y,z;

    std::cin >> m >> n;
    std::vector<ll> mark;

    for(c1=0;c1<n;c1++){

        mark.push_back(0);
    }
    for(c1=0;c1<m;c1++){

        std::cin >> x;
        for(c2=0;c2<x;c2++){
            std::cin >> a;
            mark[a-1] = 1;
        }
    }

    bool fail = 0;

    for(c1=0;c1<n;c1++){
        if(mark[c1] == 0){fail = 1;}
    }

    if(fail == 0){
        std::cout << "YES\n";
    }
    else{

        std::cout << "NO\n";
    }

	return 0;
}