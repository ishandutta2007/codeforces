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
std::vector<ll> X;
std::vector<ll> P;
std::vector<ll> ind;
std::vector<std::vector<ll> > ST(210000 , std::vector<ll>());
std::vector<std::vector<ll> > STX(210000 , std::vector<ll>());


ll rmp(ll i2, ll j){
   // cout << i2 << " " << j << "\n";
ll i = max(i2,ll(0));
ll a = 1;
ll b = 0;
if(i==j){return ST[i][0];}
while(i+2*a <= j)
{
    b++;
    a *= 2;
}

return min(ST[i][b] , rmp(i+a , j));
}

ll rmx(ll i2, ll j){
ll i = max(i2,ll(0));
ll a = 1;
ll b = 0;
if(i==j){return STX[i][0];}
while(i+2*a <= j)
{
    b++;
    a *= 2;
}
ll p1 = ST[i][b];
ll p2 = rmp(i+a , j);
ll x1 = STX[i][b];
ll x2 = rmx(i+a , j);

if(p1 == p2){return x1;}
else{if(p1 < p2){return x1;}else{return x2;}}
}

ll bsi(ll r){

ll a = 0;
ll b = m-1;
ll c;
if(X[ind[0]] > r){return -1;}
while(a+1 < b){
    c = (a+b)/2;
    if(X[ind[c]] <= r){
        a = c;
    }
    else{b = c;}
}
if(X[ind[b]] <= r){return b;}
return a;
}

ll f(ll nu , ll i ,ll curr){
    ll x;
    ll p;
   // cout << nu << " " << i << " " << curr << "\n";
    if(i == -1){x = 0;p=0;}
    else{x = X[ind[i]]; p = P[ind[i]];}
    if(nu >= d-x){return curr;}
    if(d-x <= n){
        if(rmp(i,m-1) == p){return  curr+(d-x-nu)*p;}
    }
    ll im = bsi(x+n);
   // cout << im << "\n";
    if(im == -1 || im == i){
            if(d-x <= n){
                return curr+(d-x-nu)*p;
            }
            else{
            return -100000000000000000ll;}
    }
    ll pm = rmp(i+1,im);
    ll xm = rmx(i+1,im);
    ll j = bsi(xm);
    if(P[ind[j]] != pm || X[ind[j]] != xm){std::cout<< "gfdshdf";}
    ll c;
    for(c = i+1; c <= j; c++){
        if(P[ind[c]] <= p || c == j){break;}
    }
    pm = P[ind[c]];
    xm = X[ind[c]];
   // std::cout << i+1 << " " << im << "     pm: " << pm << "  xm: " << xm << "  j: " << j <<"   "<< P[ind[j]] << "\n";
    if(pm < p){return  f(0,c,curr + (xm-x-nu)*p);}
    else{return f(n - xm + x , c , curr + (n-nu) * p);}
}

bool comp(ll i, ll j){
return X[i] < X[j];}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    ll s;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   std::cin >> d >> n >> m;
   for(c1=0;c1<m;c1++){
    std::cin >> a >> b;
    X.push_back(a);
    P.push_back(b);
    ind.push_back(c1);
   }
   std::sort(ind.begin(),ind.end(),comp);

    c = 1;
   for(c1 = 0; c1 < 35; c1++){
        for(c2=0;c2<m;c2++){
            a = ind[c2];
            //cout << a << " ";
            if(c2+c-1 < m){
                if(c == 1){
                    ST[c2].push_back(P[ind[c2]]);
                    STX[c2].push_back(X[ind[c2]]);
                }
                else{
                    //b = ind[c2+c-1];
                    ll x1 = STX[c2][c1-1];
                    ll p1 = ST[c2][c1-1];
                    ll x2 = STX[c2+c/2][c1-1];
                    ll p2 = ST[c2+c/2][c1-1];

                    if(p1 == p2){
                        if(x1 < x2){
                            ST[c2].push_back(p1);
                            STX[c2].push_back(x1);
                        }
                        else{
                            ST[c2].push_back(p2);
                            STX[c2].push_back(x2);
                        }
                    }
                    else{
                        if(p1 < p2){
                            ST[c2].push_back(p1);
                            STX[c2].push_back(x1);
                        }
                        else{
                            ST[c2].push_back(p2);
                            STX[c2].push_back(x2);
                        }
                    }
                }
            }
        }
        c *= 2;
   }
    ll ans = f(n,-1,0);
    if(ans < 0){std::cout << -1 << "\n";}
    else{std::cout << ans << "\n";}



	return 0;
}