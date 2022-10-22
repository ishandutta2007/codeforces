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

std::vector<ll> U;
std::vector<ll> D;
std::vector<ll> L;
std::vector<ll> R;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;

    ll ans = 0;


    std::cin >> n;
    std::cin >> s;

    for(c1=0;c1<n;c1++){
        for(c2=c1+1;c2<=n;c2++){
            ll u = 0;
            ll r = 0;
            ll l = 0;
            ll d = 0;

            for(c3 = c1; c3 < c2; c3++){
                if(s[c3] == 'U'){u++;}
                if(s[c3] == 'D'){d++;}
                if(s[c3] == 'L'){l++;}
                if(s[c3] == 'R'){r++;}
            }

            if(l==r && u==d){ans++;}
        }
    }
    std::cout << ans << "\n";
	return 0;
}