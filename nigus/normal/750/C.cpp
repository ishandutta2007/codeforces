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
ll T;

ll mi1 = big;
ll ma2 = -big;

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,d,e;

    cin >> n;
    ll rat = 0;
    for(c1 = 0; c1 < n; c1++){
        cin >> c >> a;
        if(a == 1){
            mi1 = min(mi1 , rat);
        }
        if(a == 2){
            ma2 = max(ma2 , rat);
        }
        rat += c;
    }

    if(ma2 == -big){
        cout << "Infinity\n";
    }
    else{

        if(mi1 <= ma2){
            cout << "Impossible\n";
        }
        else{
            cout << rat - ma2+1899 << "\n";
        }

    }

    return 0;
}