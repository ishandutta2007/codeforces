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
ll nt;
ll T;

ll TWO[20] = {0};

vector<ll> inds(ll level , bool par){
vector<ll> ANS;
for(ll c1 = 0; c1 < n; c1++){
    if((c1/TWO[level])%2 == par){
        ANS.push_back(c1);
    }
}
return ANS;
}


int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int c1,c2,c3,c4,c5,c6;
    ll a,b,c,e;

    cin >> n;

    ll t = 1;

    for(c1 = 0; c1 < 15; c1++){
        TWO[c1] = t;
        t *= 2;
    }

    nt = 1;
    while(nt < n)nt*=2;

    ll ANS[1001] = {0};
    for(c1 = 0; c1 < n; c1++){
        ANS[c1] = 1000000001;
    }

    for(c1 = 0; c1 < 10; c1++){
        vector<ll> I1 = inds(c1 , 0);
        bool in1[1001] = {0};
        if(I1.size() > 0){
            cout << I1.size() << "\n";
            for(c2 = 0;  c2 < I1.size(); c2++){
                cout << I1[c2]+1 << " ";
                in1[I1[c2]] = 1;
            }
            cout.flush();
            for(c2 = 0; c2 < n; c2++){
                cin >> a;
                if(in1[c2] == 0)ANS[c2] = min(ANS[c2] , a);
            }
        }
        I1.clear();
        I1 = inds(c1 , 1);
        bool in2[1001] = {0};
        if(I1.size() > 0){
            cout << I1.size() << "\n";
            for(c2 = 0;  c2 < I1.size(); c2++){
                cout << I1[c2]+1 << " ";
                in2[I1[c2]] = 1;
            }
            cout.flush();
            for(c2 = 0; c2 < n; c2++){
                cin >> a;
                if(in2[c2] == 0)ANS[c2] = min(ANS[c2] , a);
            }
        }
    }

    cout << "-1\n";
    for(c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << " ";
    }

    return 0;
}