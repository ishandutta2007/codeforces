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

vector<ll> L;
vector<ll> R;

ll l,r;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,c;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    cin >> n;
    l = 0;
    r = 0;

    ll ans = 0;

    for(c1 = 0; c1 < n; c1++){

        cin >> x >> y;
        l+=x;
        r+=y;
        L.push_back(x);
        R.push_back(y);
    }

   ll best = abs(l-r);

   for(c1 = 0; c1 < n; c1++){

        ll l2 = R[c1]-L[c1]+l;
        ll r2 = L[c1]-R[c1]+r;

        if(abs(l2-r2) > best){
            best = abs(l2-r2);
            ans = c1+1;
        }

   }
    cout << ans << "\n";

	return 0;
}