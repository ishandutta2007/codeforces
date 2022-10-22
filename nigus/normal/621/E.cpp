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
ll n,m,k,b,x;
ll T;

std::map<ll,ll> M;
std::set<ll> S;
std::vector<ll> dig;

ll upp(ll i, ll j, ll mod){
if(j == 0){return 1ll;}
if(j == 1){return i;}
ll a = upp(i,j/2,mod);
if(j%2==0){
    return (a*a)%mod;
}
else{
    ll c = (a*a)%mod;
    return (c*i)%mod;
}
}

ll modinv(ll t){
ll ut = 1;
ll c = 0;
while((ut*t)%x != 1){

    ut *= t;
    ut %= x;
    c++;
    if(c == 105){return -1;}
}
return ut;
}

ll gcd(ll i, ll j){
if(i == 0 && j==0){return 1;}
if(j == 0){return i;}
return gcd(j,i%j);
}

ll dp(ll nb , ll mod){

    ll c1,c2,c3;
    ll p,q,r,rest,mi;
    ll ans = 0;
    if(nb == 0){return 1ll;}
    if(nb == 1){
        for(c1 = 1;c1 < 10; c1++){
            if(c1%x == mod){ans+=dig[c1];}
        }
        //cout << ans << " fds\n";
        return (ans%big);
    }

    if(S.find(nb*1000+mod) != S.end()){return M[nb*1000+mod];}
    r = nb / 2;
    ll tio = upp(10,r,x);
    mi = modinv(tio);
    if(mi == -1){

    for(c1 = 0; c1 < x; c1++){
        q = dp(r,c1);
        rest = (mod+1000*x-c1)%x;
        //ll rest2 = rest / gcd(rest,tio);
        //ll tio2 = tio / gcd(rest,tio);
        //ll mi2 = modinv(tio2);
        p=0;
        //if(mi2 != -1){
            for(c2=0;c2<x;c2++){
                if((tio*c2)%x == rest%x){
                    p += dp(nb-r , c2);
                    p %= big;
                }
            }
            ans += (p*q)%big;
            ans %= big;
       // }
       // cout << c1 << "     " << p << " " << q << "   tio: " << tio << "\n";
    }
    //cout << p << " " << dp(r,mod) << "\n";
    }
    else{
    for(c1 = 0; c1 < x; c1++){
        q = dp(r,c1);
        rest = (mod+1000*x-c1)%x;
        p = dp(nb-r , (rest*mi)%x);
        ans += (p*q)%big;
        ans %= big;
    }
    }
    S.insert(1000*nb+mod);
    M[1000*nb+mod] = ans;
    return ans;

}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll y,z;
    ll a,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    std::cin >> n >> b >> k >> x;

    for(c1=0;c1<=10;c1++){dig.push_back(0);}
    for(c1=0;c1<n;c1++){
        std::cin >> a;
        dig[a]++;
    }
    std::cout << dp(b,k%x) << "\n";
	return 0;
}