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

string alfa = "abcdefghijklmnopqrstuvwxyz";

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,g;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    cin >> s;
    ll ns = 0;
    bool sw = 0;
    for(c1 = 0; c1 < s.length(); c1++){

        if(s[c1] != 'a' && ns == 0){
            sw = 1;
        }

        if(s[c1] == 'a'){
            sw = 0;
        }

        if(sw == 1 || (c1 == s.length()-1 && ns==0)){
            s[c1] = alfa[(ll(s[c1])-97+25)%26];
            ns++;
        }


    }
    cout << s;

	return 0;
}