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
using namespace std::chrono;

/*
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
*/

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k,r;


vector<ll> P;

ll mark[100000] = {0};

bool test(ll i){
if(i < 0)return 0;
for(ll c1 = 2; c1*c1 <= i; c1++){
    if(i%c1 == 0)return 0;
}
return 1;
}




int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c,e;

    for(c1 = 2; c1 < 100000; c1++){
        if(mark[c1] == 0){
            P.push_back(c1);
            for(c2 = c1*c1; c2 < 100000; c2+= c1){
                mark[c2] = 1;
            }
        }
    }

    cin >> n;

    if(test(n)){
        cout << 1 << "\n";
    }
    else{
        ll ans = 3;

        for(c1 = 0; c1 < P.size(); c1++){
            if(test(n-P[c1])){ans = 2;
           // cout << P[c1] << " " << n-P[c1] << "\n";
            break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}