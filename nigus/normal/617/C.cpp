#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll n,m;

std::vector<ll> X;
std::vector<ll> Y;
std::vector<ll> R1;
std::vector<ll> R2;
std::vector<ll> sr;
std::vector<ll> ind;
std::vector<ll> ind2;
std::vector<ll> MA;
ll x1,x2,y1,y2;

bool comp(ll i, ll j){
return R1[i]<R1[j];
}

bool comp2(ll i, ll j){
return R2[i]<R2[j];
}

int main()
{
    ll c1,c2,c3;
    ll a,b,c,d;

    std::cin >> n >> x1 >> y1 >> x2 >> y2;

    for(c1 = 0; c1< n; c1++){
        std::cin >> a >> b;
        c = (x1-a)*(x1-a) + (y1-b)*(y1-b);
        d = (x2-a)*(x2-a) + (y2-b)*(y2-b);
        R1.push_back(c);
        R2.push_back(d);
        sr.push_back(c+d);
        X.push_back(a);
        ind.push_back(c1);
        ind2.push_back(c1);
        Y.push_back(b);
    }
    std::sort(ind.begin(),ind.end(),comp);
    std::sort(ind2.begin(),ind2.end(),comp2);
    ll ma = 0;
    ll ans = -1;
    ll ans2 = -1;
    if(n == 1){ans = min(R1[0],R2[0]);}else{
    for(c1 = 0; c1<n;c1++){
        ma = 0;
        for(c2 = c1+1; c2<n;c2++){
            a = ind[c2];
            if(R2[a] > ma){ma = R2[a];}
        }
        b = ma + R1[ind[c1]];
        if(b < ans || ans == -1){ans = b;}
    }

    for(c1 = 0; c1<n;c1++){
        ma = 0;
        for(c2 = c1+1; c2<n;c2++){
            a = ind2[c2];
            if(R1[a] > ma){ma = R1[a];}
        }
        b = ma + R2[ind2[c1]];
        if(b < ans2 || ans2 == -1){ans2 = b;}
    }


    }
    a = min(ans,ans2);
    if(a == -1){a = max(ans,ans2);}
    std::cout << a << "\n";




    return 0;
}