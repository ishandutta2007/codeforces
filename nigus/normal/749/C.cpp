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


vector<ll> point;
vector<bool> bel;

ll death[2] = {0};

ll life[2] = {0};

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,d,e;

    cin >> n;
    string s;
    cin >> s;
    for(c1 = 0; c1 < n; c1++){
        if(s[c1] == 'D'){
            bel.push_back(0);
            life[0]++;
        }
        else{
            bel.push_back(1);
            life[1]++;
        }
        point.push_back((c1+1)%n);
    }

    ll n2 = n;
    ll i = 0;
    ll prev = n-1;
    while(n2 > 1 && life[0] > 0 && life[1] > 0){
        //cout << i <<" " << life[0] << " " << life[1] << "\n";
        if(death[bel[i]] != 0){
            death[bel[i]]--;
            point[prev] = point[i];
            life[bel[i]]--;
            i = point[i];
            n2--;
        }
        else{
            death[bel[i]^1]++;
            prev = i;
            i = point[i];
        }

    }

    if(bel[i] == 0){
        cout << "D\n";
    }
    else{
        cout << "R\n";
    }

    return 0;
}