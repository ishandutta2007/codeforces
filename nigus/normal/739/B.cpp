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

vector<vector<ll> > C(300000 , vector<ll>());
vector<vector<ll> > CW(300000 , vector<ll>());
vector<ll> B;
ll deg[300000] = {0};
ll dist[300000] = {0};

ll CU[300000] = {0};

ll EU[300000] = {0};

ll ANS[300000] = {0};

void dfs1(ll i , ll w){
    dist[i] = w;

    for(ll c1 = 0; c1 < deg[i]; c1++){
        dfs1(C[i][c1] , w + CW[i][c1]);
    }
}

void dfs2(ll i, ll d){

if(i != 0){

    ll l = 0;
    ll r = d-1;

    if(dist[i] <= B[i]){
        CU[i] += 1;
        CU[0] -= 1;
    }
    else{
        if(dist[i] - dist[EU[r]] <= B[i]){
            while(l < r-1){
                ll mid = (l+r)/2;

                if(dist[i] - dist[EU[mid]] <= B[i]){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            CU[i]++;
            CU[EU[r]]--;
        }
    }
}

EU[d] = i;
for(ll c1 = 0; c1 < deg[i]; c1++){
    dfs2(C[i][c1] , d+1);
}
}


void dfs3(ll i){
    ll ans = 0;
    for(ll c1 = 0; c1 < deg[i]; c1++){
        dfs3(C[i][c1]);
        ans += CU[C[i][c1]];
        CU[i] += CU[C[i][c1]];
    }
    ANS[i] = ans;
}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c,e;

    cin >> n;
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        B.push_back(a);
    }

    for(c1 = 1; c1 < n; c1++){
        cin >> a >> b;
        a--;
        C[a].push_back(c1);
        CW[a].push_back(b);
        deg[a]++;
    }
    dfs1(0,0);
    dfs2(0,0);
    dfs3(0);

    for(c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << " ";
    }

    return 0;
}