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
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    a = 0;
    b = 0;
    string s1,s2,s3;
    s1 = "Mishka\n";
    s2 = "Chris\n";
    s3 = "Friendship is magic!^^\n";

    for(c1 = 0; c1 < n; c1++){
        cin >> c >> e;
        if(c > e){a++;}
        if(e > c){b++;}
    }

    if(a > b){cout << s1;}
    if(b > a){cout << s2;}
    if(a == b){cout << s3;}
	return 0;
}