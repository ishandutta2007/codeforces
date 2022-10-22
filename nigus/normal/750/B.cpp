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

    ll lon = 0;
    bool fail = 0;
    for(c1 = 0; c1 < n; c1++){

        string s;
        cin >> a >> s;
        if(lon == 0 && s[0] != 'S')fail = 1;
        if(lon == 20000 && s[0] != 'N')fail = 1;
        if(s[0] == 'N')lon -= a;
        if(s[0] == 'S')lon += a;
        if(lon < 0 || lon > 20000)fail = 1;

    }

    if(lon != 0)fail = 1;

    if(fail == 1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }

    return 0;
}