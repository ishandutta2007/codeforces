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
#include <cstring>
#include <random>
#include <chrono>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,d,h,k,w,x;
//ll T;

vector<ll> A;


int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m;

    ll a1 = (n+5)/5 - 1;
    ll a2 = (n+6)/5 - 1;
    ll a3 = (n+7)/5 - 1;
    ll a4 = (n+8)/5 - 1;
    ll a5 = (n+9)/5 - 1;






    ll ans = 0;

    for(c1 = 1; c1 <= m; c1+=5){
        ans += a2;
    }
    for(c1 = 2; c1 <= m; c1+=5){
        ans += a3;
    }
    for(c1 = 3; c1 <= m; c1+=5){
        ans += a4;
    }
    for(c1 = 4; c1 <= m; c1+=5){
        ans += a5;
    }
    for(c1 = 5; c1 <= m; c1+=5){
        ans += a1;
    }

    cout << ans << "\n";

	return 0;

}