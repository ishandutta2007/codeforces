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
ll n,m,q,k;
ll T;

std::vector<ll> X;
std::vector<ll> Y;
std::vector<ll> ind;

bool comp1(ll i, ll j){
return X[i]+Y[i] < X[j]+Y[j];
}
bool comp2(ll i, ll j){
return X[i]-Y[i] < X[j]-Y[j];
}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n;
    b = 0;
    for(c1=0;c1<n;c1++){
        std::cin >> a >> b;
        X.push_back(a);
        Y.push_back(b);
        ind.push_back(c1);
    }

    std::sort(ind.begin(),ind.end(),comp1);
    ll nu = 1;
    ll ans = 0;
    for(c1=0;c1<n-1;c1++){
        a = ind[c1];
        b = ind[c1+1];
        if(X[a]+Y[a] == X[b]+Y[b]){
            nu++;
        }
        else{
            ans += (nu*(nu-1))/2;
            nu = 1;
        }
    }

    ans += nu*(nu-1)/2;

    std::sort(ind.begin(),ind.end(),comp2);
    nu = 1;
    for(c1=0;c1<n-1;c1++){
        a = ind[c1];
        b = ind[c1+1];
        if(X[a]-Y[a] == X[b]-Y[b]){
            nu++;
        }
        else{
            ans += (nu*(nu-1))/2;
            nu = 1;
        }
    }

    ans += nu*(nu-1)/2;

    std::cout << ans << "\n";


	return 0;
}