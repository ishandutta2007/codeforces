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
using namespace std::chrono;

/*
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
*/

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k,r;
ll T;

vector<ll> A1;
vector<ll> A2;
vector<ll> ind;

vector<ll> X;
vector<ll> Y;

void add(ll x, ll y){
bool fail = 0;
for(ll c1 = 0; c1 < A1.size(); c1++){
    if(A1[c1] == x && A2[c1] == y){
        fail = 1;
    }
}
if(fail == 0){A1.push_back(x);A2.push_back(y);}
}

void solve(){

if(ind[0] == 3){
    ll x = (X[ind[1]] + X[ind[2]] - X[ind[3]]);
    ll y = (Y[ind[1]] + Y[ind[2]] - Y[ind[3]]);
    add(x,y);

}
if(ind[1] == 3){
    ll x = X[ind[3]] - X[ind[2]] +  X[ind[0]];
    ll y = Y[ind[3]] - Y[ind[2]] +  Y[ind[0]];
    add(x,y);
}
if(ind[2] == 3){
    ll x = X[ind[3]] - X[ind[1]] +  X[ind[0]];
    ll y = Y[ind[3]] - Y[ind[1]] +  Y[ind[0]];
    add(x,y);
}
if(ind[3] == 3){
    ll x = X[ind[2]] + X[ind[1]] -  X[ind[0]];
    ll y = Y[ind[2]] + Y[ind[1]] -  Y[ind[0]];
    add(x,y);
}

}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,d,e;

    cin >> a >> b;
    X.push_back(a);
    Y.push_back(b);

    cin >> a >> b;
    X.push_back(a);
    Y.push_back(b);

    cin >> a >> b;
    X.push_back(a);
    Y.push_back(b);

    ind.push_back(0);
    ind.push_back(1);
    ind.push_back(2);
    ind.push_back(3);


    for(c1 = 0; c1 < 24; c1++){
        solve();
        next_permutation(ind.begin() , ind.end());
    }

    cout << A1.size() << "\n";

    for(c1 = 0; c1 < A1.size(); c1++){
        cout << A1[c1] << " " << A2[c1] << "\n";
    }

    return 0;
}