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
ll n,m,q,h,k,w;
ll T;

ll parse(string s){
ll ans = 0;

for(ll c1 = 0; c1 < s.length(); c1++){
    ans *= 10;
    if(s[c1] == '0')ans += 0;
    if(s[c1] == '1')ans += 1;
    if(s[c1] == '2')ans += 2;
    if(s[c1] == '3')ans += 3;
    if(s[c1] == '4')ans += 4;
    if(s[c1] == '5')ans += 5;
    if(s[c1] == '6')ans += 6;
    if(s[c1] == '7')ans += 7;
    if(s[c1] == '8')ans += 8;
    if(s[c1] == '9')ans += 9;

}
return ans;
}


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,g,c;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    cin >> s;
    n = s.length();
    char ch = s[n-1];
    string s2 = "";

    for(c1 = 0; c1 < n-1; c1++){
        s2 += s[c1];
    }

    n =  parse(s2)-1;

    ll ans = 0;



    ans += 4*(n/4) + 3*4*(n/4);

   // cout << ans << "\n";

    if(n%2 == 1)ans += 7;

    if(ch == 'f')ans += 0;
    if(ch == 'e')ans += 1;
    if(ch == 'd')ans += 2;
    if(ch == 'a')ans += 3;
    if(ch == 'b')ans += 4;
    if(ch == 'c')ans += 5;

    cout << ans+1 << "\n";

	return 0;
}