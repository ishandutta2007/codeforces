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



int main()
{
    ll c1,c2,c3;
    ll a,b,c,d;
    ll x1,x2;
    for(c1 = 0; c1 <3;c1++){
    std::cin >> x1 >> x2;
    X.push_back(x1);
    Y.push_back(x2);
    }
    ll ans = 3;
    if(X[0] == X[1] && (Y[2] == min(min(Y[0],Y[1]),Y[2]) || Y[2] == max(max(Y[0],Y[1]),Y[2]) )){
        ans = 2;
    }
    if(X[1] == X[2] && (Y[0] == min(min(Y[0],Y[1]),Y[2]) || Y[0] == max(max(Y[0],Y[1]),Y[2]) )){
        ans = 2;
    }
    if(X[0] == X[2] && (Y[1] == min(min(Y[0],Y[1]),Y[2]) || Y[1] == max(max(Y[0],Y[1]),Y[2]) )){
        ans = 2;
    }

    if(Y[0] == Y[1] && (X[2] == min(min(X[0],X[1]),X[2]) || X[2] == max(max(X[0],X[1]),X[2]) )){
        ans = 2;
    }
    if(Y[1] == Y[2] && (X[0] == min(min(X[0],X[1]),X[2]) || X[0] == max(max(X[0],X[1]),X[2]) )){
        ans = 2;
    }
    if(Y[0] == Y[2] && (X[1] == min(min(X[0],X[1]),X[2]) || X[1] == max(max(X[0],X[1]),X[2]) )){
        ans = 2;
    }

    if(X[0] == X[1] && X[1] == X[2]){
        ans = 1;
    }
    if(Y[0] == Y[1] && Y[1] == Y[2]){
        ans = 1;
    }
    std::cout << ans << "\n";
    return 0;
}