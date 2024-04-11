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

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k,q;
ll T;

ll ctn(char ch){
return ll(ch)-48;}
int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    std::cin >> s;
    n = s.length();
    ll ans = 0;
    for(c1 = 0; c1<n-1;c1++){
       if((ctn(s[c1])*10+ctn(s[c1+1])) % 4 == 0){
        ans += c1+1;
       }
       if(ctn(s[c1]) % 4 == 0){ans ++;}
    }
    if(ctn(s[n-1]) % 4 == 0){ans ++;}

    std::cout << ans << "\n";
	return 0;
}