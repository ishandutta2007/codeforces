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
ll n,m,q,h,k,w,r,c;
ll T;
int a00,a10,a01,a11;
ll n0,n1;


map<ll,ll> trinv;
ll tri[100000];
void setup(){
ll ans = 0;
for(ll c1 = 1; c1 < 100000; c1++){
    trinv[ans] = c1;
    tri[c1] = ans;
    ans += c1;
}
}


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,g;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    scanf("%d %d %d %d" , &a00, &a01, &a10, &a11);

    bool fail = 0;

    setup();

    if(a00 + a01 + a10 == 0){

        if(trinv.find(a11) != trinv.end()){
        n1 = trinv[a11];
        for(c1 = 0; c1 < n1; c1++){
            printf("1");
        }
        }
        else{
            printf("Impossible\n");
        }

        return 0;
    }

    if(a11 + a01 + a10 == 0){

        if(trinv.find(a00) != trinv.end()){
        n0 = trinv[a00];
        for(c1 = 0; c1 < n0; c1++){
            printf("0");
        }
        }
        else{
            printf("Impossible\n");
        }

        return 0;
    }

    if(trinv.find(a00) != trinv.end()){
        n0 = trinv[a00];
    }
    else{
        fail = 1;
    }

    if(trinv.find(a11) != trinv.end()){
        n1 = trinv[a11];
    }
    else{
        fail = 1;
    }

    if(fail == 0){
        if(n0*n1 == a10+a01){

            n = n0+n1;
            for(c1 = 0; c1 < n; c1++){
                if(a01 >= n1){
                    printf("0");
                    n0--;
                    a01 -= n1;
                }
                else{
                    printf("1");
                    n1--;
                    a10 -= n0;
                }
            }


        }
        else{
            printf("Impossible\n");
        }


    }
    else{

        printf("Impossible\n");

    }

	return 0;
}