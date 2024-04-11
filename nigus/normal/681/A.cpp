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
typedef int ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,d,h,k,w,x;
//ll T;

vector<ll> A;

ll main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;
    bool yes = 0;
    for(c1 = 0; c1 < n; c1++){
        string s;
        cin >> s >> a >> b;
        if(a >= 2400 && a < b){
            yes = 1;
        }
    }

    if(yes == 1){
        cout << "YES\n";
    }else{
    cout << "NO\n";}

	return 0;
}