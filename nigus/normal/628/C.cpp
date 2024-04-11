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
return ll(ch)-97;}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    std::cin >> n >> k;
    std::cin >> s;
    string ans;
    bool fail = 0;
    bool done = 0;
    for(c1 = 0; c1<n;c1++){
        if(done == 0){
        a = ctn(s[c1]);
        b = 25 - ctn(s[c1]);

        if(k < a || k < b){
            if(k < a){
                ans += char(a-k+97);
                k = 0;
                done = 1;
            }
            else{
                ans += char(a+k+97);
                k = 0;
                done = 1;
            }

        }
        else{
            if(a > b){
                ans += 'a';
                k -= a;
            }
            else{
                ans += 'z';
                k -= b;
            }
        }
        }
        else{ans += s[c1];}
    }

    if(k > 0){std::cout << -1 << "\n";}
    else{
        std::cout << ans << "\n";
    }
	return 0;
}