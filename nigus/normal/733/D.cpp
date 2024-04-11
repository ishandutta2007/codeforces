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

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,h,k,w;
ll T;

vector<ll> X;
vector<ll> Y;
vector<ll> Z;

ll max1 = 0;
ll ind1 = 0;

ll max2 = 0;
ll ind2a = 0;
ll ind2b = 0;

vector<ll> P;
vector<ll> Q;

map<ll,ll> M;
map<ll,ll> other;

ll hash1(ll i, ll j){
ll i2 = min(i,j);
ll j2 = max(i,j);
return 1000000000*i2 + j2;
}

ll min3(ll i, ll j, ll p){

return min(min(i,j),p);
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,c;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    cin >> n;

    for(c1 = 0; c1 < n; c1++){

        cin >> x >> y >> z;
        X.push_back(x);
        Y.push_back(y);
        Z.push_back(z);
        set<ll> S;
        if(min(x,min(y,z)) > max1){max1 = min(x,min(y,z)) ; ind1 = c1;}

        ll h1,h2,h3;
        h1 = hash1(x,y);
        h2 = hash1(z,y);
        h3 = hash1(x,z);

        if(M.find(h1) == M.end()){M[h1] = 0;}
        if(M.find(h2) == M.end()){M[h2] = 0;}
        if(M.find(h3) == M.end()){M[h3] = 0;}

        if(z > M[h1]){M[h1] = z; other[h1] = c1;}
        if(x > M[h2]){M[h2] = x; other[h2] = c1;}
        if(y > M[h3]){M[h3] = y; other[h3] = c1;}

    }

    for(c1 = 0; c1 < n; c1++){

        x = X[c1];
        y = Y[c1];
        z = Z[c1];

        ll h1,h2,h3;
        h1 = hash1(x,y);
        h2 = hash1(z,y);
        h3 = hash1(x,z);

        ll ot,m2;

        ot = other[h1];
        if(ot != c1){
            m2 = z+M[h1];
            ll tempans = min3(x,y,m2);
            if(tempans > max2){
                max2 = tempans;
                ind2a = ot;
                ind2b = c1;
            }
        }


        ot = other[h2];
        if(ot != c1){
            m2 = x+M[h2];
            ll tempans = min3(z,y,m2);
            if(tempans > max2){
                max2 = tempans;
                ind2a = ot;
                ind2b = c1;
            }
        }


        ot = other[h3];
        if(ot != c1){
            m2 = y+M[h3];
            ll tempans = min3(x,z,m2);
            if(tempans > max2){
                max2 = tempans;
                ind2a = ot;
                ind2b = c1;
            }
        }

    }

    if(max1 > max2){
        cout << "1\n";
        cout << ind1+1 << "\n";
    }
    else{
        cout << "2\n";
        cout << ind2a+1 << " " << ind2b+1 << "\n";
    }

	return 0;
}