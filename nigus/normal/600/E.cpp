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

ll start = 0;

vector<ll> col;
vector<vector<ll> > C(100001 , vector<ll>());
ll deg[100001] = {0};

ll cnt[100001] = {0};
ll freq[100001] = {0};
ll ma = 0;

ll sz[100001] = {0};

bool mark[100001] = {0};

bool BI[100001] = {0};

ll ANS[100001] = {0};

ll bi = -1;

void dfs1(ll i, ll par){
    sz[i] = 1;
    for(ll c1 = 0; c1 < deg[i]; c1++){
        ll a = C[i][c1];
        if(a != par){
            dfs1(a,i);
            sz[i] += sz[a];
        }
    }
}

void upd(ll i, ll par){
    cnt[col[i]]++;
    ll cci = cnt[col[i]];
    ll ci1 = col[i]+1;
    freq[cci] += ci1;
    freq[cci - 1] -= ci1;
    if(freq[ma+1] != 0)ma++;
    for(ll c1 = 0; c1 < deg[i]; c1++){
        ll a = C[i][c1];
        if(a != par && BI[a] == 0){
            upd(a,i);
        }
    }
}

void deupd(ll i, ll par){
    cnt[col[i]]--;
    ll cci = cnt[col[i]];
    ll ci1 = col[i]+1;
    freq[cci] += ci1;
    freq[cci + 1] -= ci1;
    if(freq[ma] == 0)ma--;
    for(ll c1 = 0; c1 < deg[i]; c1++){
        ll a = C[i][c1];
        if(a != par && BI[a] == 0){
            deupd(a,i);
        }
    }
}

void dfs2(ll i, ll par, bool keep){

    ll bi2 = -1;
    ll madeg = -1;
    for(ll c1 = 0; c1 < deg[i]; c1++){
        ll a = C[i][c1];
        if(a != par){
            if(sz[a] > madeg){
                bi2 = a;
                madeg = sz[a];
            }
        }
    }
    for(ll c1 = 0; c1 < deg[i]; c1++){
        ll a = C[i][c1];
        if(a != par && a != bi2){
            dfs2(a,i,0);
        }
    }

    if(bi2 != -1){
        dfs2(bi2 , i, 1);
        BI[bi2] = 1;
    }
    upd(i,par);
    ANS[i] = freq[ma];
    if(bi2 != -1){
        BI[bi2] = 0;
    }
    if(keep == 0){
        deupd(i,par);
    }
}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,d,e;

    cin >> n;
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        a--;
        col.push_back(a);
        freq[0] += c1+1;
    }

    for(c1 = 0; c1 < n-1; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    start = 0;
    dfs1(start,-1);
    dfs2(start,-1,1);
    for(c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << " ";
    }
    return 0;
}