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

ll ANS[1000][1000];

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n >> k;
    k--;
    c3 = 1;
    for(c1=0;c1<n;c1++){
        for(c2=0;c2<k;c2++){
            ANS[c1][c2] = c3;
            c3++;
        }
    }
    ll ans = 0;
    for(c1 = 0; c1<n;c1++){
        for(c2=k;c2<n;c2++){
            if(c2==k){ans += c3;}
            ANS[c1][c2] = c3;
            c3++;
        }
    }

    std::cout << ans << "\n";
    for(c1=0;c1<n;c1++){
        for(c2=0;c2<n;c2++){
            std::cout << ANS[c1][c2] << " ";
        }
        std::cout << "\n";
    }

	return 0;
}