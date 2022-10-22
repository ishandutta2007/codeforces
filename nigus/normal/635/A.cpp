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

ll upt[11][11];

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,d,e,f;
    ll r;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> r >> c >> n >> k;
    for(c1=0;c1<11;c1++){
        for(c2=0;c2<11;c2++){
            upt[c1][c2] = 0;
        }
    }
    for(c1=0;c1<n;c1++){
            std::cin >> x >> y;
            x--;
            y--;
            upt[x][y] = 1;
    }
    ll ans = 0;
    for(c1=0;c1<r;c1++){
        for(c2=0;c2<c;c2++){
            for(c3=c1;c3<r;c3++){
                for(c4=c2;c4<c;c4++){
                    ll t = 0;
                    for(c5 = c1; c5 <= c3; c5++){
                        for(c6 = c2; c6 <= c4; c6++){
                            t += upt[c5][c6];
                        }
                    }

                    if(t >= k){ans++;}

                }
            }
        }
    }
std::cout << ans << "\n";
	return 0;
}