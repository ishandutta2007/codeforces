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

std::map<ll,ll> MX;
std::map<ll,ll> MY;
std::map<ll,ll> MXY;

std::vector<ll> X;
std::vector<ll> Y;

std::vector<ll> ind;
std::vector<ll> ind2;

bool comp(ll i, ll j){
if(X[i] == X[j]){
    return Y[i] < Y[j];
}
return X[i] < X[j];
}

bool comp2(ll i, ll j){
    return Y[i] < Y[j];
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n;
    ll nxy = 0;

    for(c1=0;c1<n;c1++){
        std::cin >> a >> b;
        X.push_back(a);
        Y.push_back(b);
        ind.push_back(c1);
        ind2.push_back(c1);

    }
X.push_back(2000000000ll);
Y.push_back(2000000000ll);
ind.push_back(n);
ind2.push_back(n);
std::sort(ind.begin(),ind.end(),comp);
std::sort(ind2.begin(),ind2.end(),comp2);

b = 1;
ll nx = 0;
ll ny = 0;
d = 1;
for(c1 = 0; c1<n;c1++){

    a = ind[c1];
    c = ind[c1+1];
    if(X[a] == X[c]){b++;}
    else{nx += b * (b-1) / 2; b = 1;}

    if(X[a] == X[c] && Y[a] == Y[c]){d++;}
    else{nxy += d * (d-1) / 2; d = 1;}


}
b = 1;
for(c1 = 0; c1<n;c1++){
    a = ind2[c1];
    c = ind2[c1+1];
    //cout << Y[a] << " " << Y[c] << "\n";
    if(Y[a] == Y[c]){b++;}
    else{ny += b * (b-1) / 2; b = 1;}

}

std::cout << nx+ny-nxy << "\n";

	return 0;
}