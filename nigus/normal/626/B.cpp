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

ll R;
ll B;
ll G;

bool rt,bt,gt;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;

    ll ans = 0;
    rt = 0;
    bt = 0;
    gt = 0;

    std::cin >> n;
    std::cin >> s;
    R = 0;
    G = 0;
    B = 0;
    for(c1=0;c1<n;c1++){
        if(s[c1] == 'R'){R++;}
        if(s[c1] == 'G'){G++;}
        if(s[c1] == 'B'){B++;}
    }

    if((R+G > 1 && B > 0) || (R != 0 && G != 0) || (R == 0 && G == 0)){bt = 1;std::cout << "B";}
    if((R+B>1 && G > 0) || (R != 0 && B != 0) || (R == 0 && B == 0)){gt = 1;std::cout << "G";}
    if((B+G>1 && R > 0) || (B != 0 && G != 0) || (B == 0 && G == 0)){rt = 1;std::cout << "R";}
    std::cout << "\n";

	return 0;
}