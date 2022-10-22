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
    a = 1234;
    b = 123456;
    c = 1234567;
    bool yes = 0;

        for(c2 = 0; c2 < 10000; c2++){

            for(c3 = 0; c3 < 1000; c3++){

                m = n - c2*b - c3*c;
                if(m >= 0){
                    if(m % a == 0){yes =1;}
                }

            }

        }

        if(yes == 1){cout << "YES\n";}
        else{
            cout << "NO\n";
        }


	return 0;
}