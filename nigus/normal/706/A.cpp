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

ld dis(ll x1,ll y1, ll x2, ll y2){
return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stress.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ld ans = 999999999;

    cin >> a >> b;
    cin >> n;
    ll x;
    for(c1 = 0; c1 < n; c1++){
        cin >> x >> y >> z;
        ans = min(ans, dis(x,y,a,b)/ld(z));

    }
    cout << setprecision(18) << ans << "\n";
	return 0;
}