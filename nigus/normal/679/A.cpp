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

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,d,h,k,w;
//ll T;


ll upp(ll i, ll j){
if(j == 0){return 1;}
ll b = upp(i,j/2);
if(j%2 == 0){return (b*b)%big;}
return (((b*b)%big)*(i%big))%big;
}


int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll x,y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    vector<ll> P;

    vector<ll> P2;


    for(c1 = 2; c1 < 101; c1++){
        for(c2 = 2; c2 <= c1; c2++){
            if(c2 == c1){P2.push_back(c1);}
            if(c1%c2 == 0){break;}
        }

    }

    for(c1 = 2; c1 < 53; c1++){
        for(c2 = 2; c2 <= c1; c2++){
            if(c2 == c1){P.push_back(c1);}
            if(c1%c2 == 0){break;}
        }

    }

    ll n4 = 0;
    ll n5 = 0;
    P.push_back(4);
    P.push_back(9);
    P.push_back(25);
    P.push_back(49);
    for(c1 = 0; c1 < P.size(); c1++){
        printf("%d\n" , P[c1]);
        fflush(stdout);
        char s[3];
        scanf("%s" , s);
        if(s[0] == 'y'){
            n4++;
        }
    }

    if(n4 >= 2){
        printf("composite\n");
        fflush(stdout);
    }
    else{

        printf("prime\n");
        fflush(stdout);


    }

	return 0;
}