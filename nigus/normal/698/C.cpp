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

vector<ld> A;
vector<ld> ANS;

ll TWO[30] = {0};

ld DP[2000000] = {-1};

ld f(ll mask){

if(mask == 0){return ld(1);}
if(DP[mask] != -1){return DP[mask];}
ll mask2 = mask;

ld s = ld(0);

for(ll c1 = 0; c1 < n; c1++){
    if(mask2 % 2 == 1){
        s += A[c1];
    }mask2 /= 2;
}

ld ans = ld(0);
mask2 = mask;

for(ll c1 = 0; c1 < n; c1++){
    if(mask2 % 2 == 1){
        ans += A[c1]/(ld(1) - s + A[c1]) * f(mask ^ TWO[c1]);
    }mask2 /= 2;
}

DP[mask] = ans;
return ans;

}

int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> k;
    ld da;
    ll n2 = 0;
    vector<ll> ind;
    for(c1 = 0 ;c1 < n; c1++){
        cin >> da;
        if(da > 0){
        n2++;
        A.push_back(da);
        ANS.push_back(ld(1));
        ind.push_back(n2-1);
        }
        else{
            ind.push_back(-1);
        }
    }
m = n;
n = n2;

    TWO[0] = 1;
    for(c1 = 1; c1 < 30; c1++){
        TWO[c1] = 2*TWO[c1-1];
    }


    if(k >= n){


        for(c1 = 0; c1 < m; c1++){
            if(ind[c1] == -1){cout << "0 ";}
            else{cout << "1 ";}
        }

    }

    else{


        ll two = 1;
        for(c1 = 0; c1 < n; c1++){
            two*=2;
        }

        for(c1 = 0; c1 < two;  c1++){

            DP[c1] = -1;

        }

        for(c1 = 0; c1 < two;  c1++){

            ll nett = 0;
            c2 = c1;
            for(c3 = 0; c3 < n; c3++){
                if(c2%2 == 1){nett++;}
                c2/=2;
            }

            if(nett == k){

                ld ny = f(c1);
                c2 = c1;
            for(c3 = 0; c3 < n; c3++){
                if(c2%2 == 0){ANS[c3] -= ny;}
                c2/=2;
            }

            }


        }

        for(c1 = 0; c1 < m; c1++){
            if(ind[m] == -1){cout <<setprecision(18) <<  0 << " ";}
           else{ cout <<setprecision(18) <<  ANS[ind[c1]] << " ";}
        }

    }




	return 0;

}