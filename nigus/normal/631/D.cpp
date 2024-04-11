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
ll n,m,k,q,d;
ll T;

std::vector<ll> NA;
std::vector<ll> NB;

ll na,nb;

std::vector<char> CA;
std::vector<char> CB;

ll upp(ll a,ll b){
if(b == 0){return 1ll;}
ll c = upp(a,b/2);
if(b % 2 == 0){
    return (c*c)%big;
}
else{
    return (((c*c)%big) * (a%big))%big;
}
}

ll ctn(char ch){
if(ch == '0'){return 0ll;}
if(ch == '1'){return 1ll;}
if(ch == '2'){return 2ll;}
if(ch == '3'){return 3ll;}
if(ch == '4'){return 4ll;}
if(ch == '5'){return 5ll;}
if(ch == '6'){return 6ll;}
if(ch == '7'){return 7ll;}
if(ch == '8'){return 8ll;}
if(ch == '9'){return 9ll;}
return 0ll;
}

ll stn(string s){
ll tio = 1;
ll ans = 0;
for(ll c = s.length()-3; c >= 0; c--){
    ans += ctn(s[c]) * tio;
    tio *= 10;
}
return ans;
}

ll h1(){
    ll base = 1ll;
    ll ans = 0ll;
    for(ll c = 1; c < nb-1; c++){
        ll x = ll(CB[c]-96) * (1000001ll);
        ans += (((x + NB[c])%big) * base)%big;
        ans %= big;
        base *= 26000001ll;
        base %= big;
    }
return ans;
}

ll h2(){
    ll base = 1ll;
    ll ans = 0ll;
    for(ll c = 1; c < nb-1; c++){
        ll x = ll(CA[c]-96) * (1000001ll);
        ans += (((x + NA[c])%big) * base)%big;
        ans %= big;
        base *= 26000001ll;
        base %= big;
    }
return ans;
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   std::cin >> n >> m;
   char nu = 'R';
   na=0;
   nb=0;
   big = 800001281ll;
   for(c1=0;c1<n;c1++){
        string s;
        std::cin >> s;
        ll l = s.length();
        if(s[l-1] != nu){
            CA.push_back(s[l-1]);
            NA.push_back(stn(s));
            na++;
            nu = s[l-1];
        }
        else{
            NA[na-1] += (stn(s));
        }
   }

   nu = 'R';
   for(c1=0;c1<m;c1++){
        string s;
        std::cin >> s;
        ll l = s.length();
        if(s[l-1] != nu){
            CB.push_back(s[l-1]);
            NB.push_back(stn(s));
            nb++;
            nu = s[l-1];
        }
        else{
            NB[nb-1] += (stn(s));
        }
   }
/*
for(c1 = 0; c1<na;c1++){
    std::cout << NA[c1] << " " << CA[c1] << "\n";
}
cout << "\n";
for(c1 = 0; c1<nb;c1++){
    std::cout << NB[c1] << " " << CB[c1] << "\n";
}
*/
if(nb == 1){

    ll ans = 0;
    for(c1 = 0; c1<na; c1++){
        if(CA[c1] == CB[0] && NA[c1] >= NB[0]){
            ans += NA[c1]-NB[0]+1;
        }
    }
    std::cout << ans << "\n";

}
else{

    if(na < nb){std::cout << 0 << "\n";}
    else{
        ll ans = 0;
        x = h1();
        y = h2();

        for(c1 = nb-1 ; c1 < na; c1++){
                //cout << x << " " << y << "\n";
            if(x == y && CA[c1-nb+1] == CB[0] && CA[c1] == CB[nb-1]){
                if(NA[c1-nb+1] >= NB[0] && NA[c1] >= NB[nb-1]){
                    ans++;
                }

            }
            if(nb > 2){
            y -= (ll(CA[c1-nb+2]-96) * (1000001ll) + NA[c1-nb+2])%big;
           // cout << y;
            y = (y + big) % big;
            y *= upp(26000001ll , big-2);
            //y /= 26000001ll;
            y %= big;
            a = ll(CA[c1]-96) * (1000001ll) + NA[c1];
            a *= upp(26000001ll , nb-3);
            a %= big;
            y += a;
            y %= big;
            }
        }

        std::cout << ans << "\n";

    }
}


	return 0;
}