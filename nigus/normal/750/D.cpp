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

vector<ll> XC;
vector<ll> YC;

vector<ll> A;

ll M[600][600] = {0};
set<ll> S;

vector<ll> XT;
vector<ll> YT;
vector<ll> DT;

vector<ll> X;
vector<ll> Y;
vector<ll> D;

ll has(ll x, ll y, ll dir){
return 10000*x + 10*y + dir;
}

void transfer(ll x, ll y, ll i, ll dir){

ll x2 = x;
ll y2 = y;

//cout << x << " " << y << "  -  " << i << " " << dir << "\n";

for(ll c1 = 0; c1 < A[i]; c1++){
    M[x2][y2] = 1;
    x2 += XC[dir];
    y2 += YC[dir];
}

x2 -= XC[dir];
y2 -= YC[dir];
if(i < n-1){
    ll x3 = x2 + XC[(dir+1)%8];
    ll y3 = y2 + YC[(dir+1)%8];

    ll h1 = has(x3,y3,(dir+1)%8);

    if(S.find(h1) == S.end()){
        S.insert(h1);
        XT.push_back(x3);
        YT.push_back(y3);
        DT.push_back((dir+1)%8);
    }

    x3 = x2 + XC[(dir+7)%8];
    y3 = y2 + YC[(dir+7)%8];

    h1 = has(x3,y3,(dir+7)%8);

    if(S.find(h1) == S.end()){
        S.insert(h1);
        XT.push_back(x3);
        YT.push_back(y3);
        DT.push_back((dir+7)%8);
    }
    }
}

void solve(){
X.push_back(300);
Y.push_back(300);
D.push_back(2);

for(ll c1 = 0; c1 < n; c1++){

    S.clear();
    XT.clear();
    YT.clear();
    DT.clear();

    for(ll c2 = 0; c2 < X.size(); c2++){
        transfer(X[c2] , Y[c2] , c1 , D[c2]);
    }

    X.clear();
    Y.clear();
    D.clear();
    for(ll c1 = 0; c1 < XT.size(); c1++){
        X.push_back(XT[c1]);
        Y.push_back(YT[c1]);
        D.push_back(DT[c1]);
    }

}
}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,d,e;

    XC.push_back(1);
    YC.push_back(0);

    XC.push_back(1);
    YC.push_back(1);

    XC.push_back(0);
    YC.push_back(1);

    XC.push_back(-1);
    YC.push_back(1);

    XC.push_back(-1);
    YC.push_back(0);

    XC.push_back(-1);
    YC.push_back(-1);

    XC.push_back(0);
    YC.push_back(-1);

    XC.push_back(1);
    YC.push_back(-1);

    cin >> n;
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }

    solve();

    ll ans = 0;

    for(c1 = 0; c1 < 600; c1++){
        for(c2 = 0; c2 < 600; c2++){
            ans += M[c1][c2];
        }
    }
/*
    for(c1 = 0; c1 < 20; c1++){
        for(c2 = 0; c2 < 20; c2++){
            cout << M[290+c1][290+c2];
        }
        cout << "\n";
    }
*/
    cout << ans << "\n";

    return 0;
}