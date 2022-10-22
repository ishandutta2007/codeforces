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

    cin >> n;
    for(c1 = 0; c1 < n;c1++){
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin() , A.end());

    ll ans = 1;

    for(c1 = 0; c1 < n; c1++){

        if(A[c1] >= ans){
            ans++;
        }


    }
    cout << ans << "\n";

	return 0;

}