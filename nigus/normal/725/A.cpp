#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <random>
#include <chrono>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,h,k,w;
ll T;


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,g;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;

    c1 = 0;

    while(s[c1] == '<'){

        c1++;
        ans++;
        if(c1 == n){break;}

    }
    c1 = n-1;

     while(s[c1] == '>'){

        c1--;
        ans++;
        if(c1 == -1){break;}

    }

    cout << ans << "\n";

	return 0;
}