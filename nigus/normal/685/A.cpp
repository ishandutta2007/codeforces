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

ll F[1000][1000] = {0};



ll log7(ll i){
if(i == 0){return 1;}
ll ans = 0;
ll i2 = i;
while(i2 > 0){i2 /= 7; ans++;}
return ans;
}


int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    cin >> n >> m;

set<ll> S;
    ll l1 = log7(n-1);
    ll l2 = log7(m-1);

    ll l3 = l1+l2;


    if(l3 > 7){
        cout << "0\n";
    }
    else{

        vector<ll> A;

        for(c1 = 0; c1 < 7; c1++){
            A.push_back(c1);
        }

        ll ans = 0;
        for(c1 = 0; c1 < 5040; c1++){

            ll sev = 1;
            a = 0;
            for(c2 = 0; c2 < l1; c2++){
                a += sev*A[c2];
                sev *= 7;
            }
            b = 0;
            sev = 1;
            for(c2 = l1; c2 < l3; c2++){
                b += sev*A[c2];
                sev *= 7;
            }


            if(a < n && b < m && (S.find(a*1000000000 + b) == S.end())){ans++;

            S.insert(a*1000000000 + b);
            }

        next_permutation(A.begin() , A.end());

        }


        cout << ans << "\n";

    }




	return 0;

}