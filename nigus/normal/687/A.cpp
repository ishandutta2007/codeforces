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
ll n,m,q,d,h,k,w,x;
ll T;

vector<ll> deg;
vector<vector<ll>  > C(100001 , vector<ll>());
vector<ll> farg;

bool possible = 1;

void dfs(ll i, ll col, ll par){

if(farg[i] != -1 && farg[i] != col){
    possible = 0;
}
farg[i] = col;

ll col2 = (col+1)%2;

for(ll c = 0; c < deg[i]; c++){
    ll a = C[i][c];
    if(a != par){


        if(farg[a] != -1 && farg[a] != col2){
            possible = 0;
        }

        if(farg[a] == -1){

            dfs(a , col2 , i);

        }

    }
}
return;
}

int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll x,y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   cin >> n >> m;

   for(c1 = 0; c1 < n; c1++){
    deg.push_back(0);
    farg.push_back(-1);
   }

   for(c1 = 0; c1 < m; c1++){

    cin >> a >> b;
    a--;b--;
    deg[a]++;
    deg[b]++;
    C[a].push_back(b);
    C[b].push_back(a);

   }

for(c1 = 0; c1 < n; c1++){


    if(farg[c1] == -1){

        dfs(c1,0,-1);

    }

}

if(possible == 0){


    cout << "-1\n";

}
else{

    ll w = 0;
    b = 0;

    vector<ll> W;
    vector<ll> B;

    for(c1 = 0; c1<n; c1++){


        if(farg[c1] == 0){
            W.push_back(c1+1);
        }
        else{
            B.push_back(c1+1);
        }

    }

    cout << W.size() << "\n";

    for(c1 = 0; c1 < W.size(); c1++){
        cout << W[c1] << " ";
    }

    cout << "\n";

    cout << B.size() << "\n";

    for(c1 = 0; c1 < B.size(); c1++){
        cout << B[c1] << " ";
    }

    cout << "\n";


}



	return 0;

}