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

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,h,k,w;
ll T;



int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll m;

    string ans = "#Black&White\n";

    cin >> n >> m;
    for(c1 = 0; c1 < n; c1++){
        for(c2 = 0; c2 < m; c2++){
            char ch;
            cin >> ch;
            if(!(ch == 'G' || ch == 'W' || ch == 'B'))ans = "#Color\n";
        }
    }
    cout << ans;


	return 0;
}