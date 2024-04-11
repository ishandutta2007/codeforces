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
typedef int ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,d,h,k,w,x;
ll T;

vector<ll> A;
set<ll> S;

ll F[1000001] = {0};

ll gcd(ll i , ll j){

if(j == 0){return i;}
return gcd(j,i%j);
}


void pf(ll i){
ll i2 = i;
for(ll c = 2; c*c <= i; c++){
    if(i2 % c == 0){
    ll c2 = 0;
    while((i2 % c) == 0){
        i2 /= c;
        c2++;
    }
    if(c2 > F[c]){F[c] = c2;}
    }
}
if(i2 == 0){return;}
if(i2 != 1){
    F[i2] = max(F[i2],1);
}

return;
}



int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll x,y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   //cin >> n >> k;
    scanf("%d %d" , &n,&k);

    g = 1;


    for(c1 = 0; c1 < 1000001; c1++){
        F[c1] = 0;
    }

   for(c1 = 0; c1 < n; c1++){
    //cin >> a;
    scanf("%d",&a);
    A.push_back(a);
    a = gcd(a,k);
    if(S.find(a) == S.end()){pf(a);S.insert(a);}
   }
/*
   for(c1 = 0; c1 < 11; c1++){
    cout << F[c1] << "  " << c1 << "\n";
   }
*/
    ll k2 = k;
    for(c1 = 2; c1 < 1000001; c1++){

        if(F[c1] != 0){

            for(c2 = 0; c2 < F[c1]; c2++){
                if(k2 % c1 == 0){k2 /= c1;}
                else{break;}
            }
        }
    }

    if(k2 == 1){

        //cout << "Yes\n";
        printf("Yes\n");

    }

    else{

        //cout << "No\n";
        printf("No\n");

    }

	return 0;

}