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



int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,d,e;

    cin >> n;
    cout << n/2 << "\n";
    if(n%2 == 1){
        cout << "3 ";
        n -= 3;
    }
    if(n%2 == 0){
        for(c1 = 0; c1 < n/2; c1++){
            cout << "2 ";
        }
    }

    return 0;
}