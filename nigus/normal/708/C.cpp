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
ll n,m,q,h,k,w,r;
ll T;

vector<vector<ll> > C(400001 , vector<ll>());
ll deg[400001] = {0};

vector<vector<ll> > CS(400001 , vector<ll>());

ll ANS[400001] = {0};
ll cent[400001] = {0};

vector<ll> B;
vector<ll> SB;
vector<ll> cents;

ll dfs(ll i ,ll par){
    ll pari = -1;
    ll ans = 1;
    for(ll c1 = 0 ;c1 < deg[i]; c1++){
        ll b = C[i][c1];
        if(b != par){
            ll x = dfs(b,i);
            CS[i].push_back(x);
            ans += x;
        }
        else{
            pari = c1;
            CS[i].push_back(-1);
        }
    }
    if(pari != -1){
        CS[i][pari] = n-ans;
    }
    return ans;
}


void dfs2(ll i, ll par, ll best){
if(B[i]-best <= n/2){ANS[i] = 1;}
for(ll c1 = 0; c1 < deg[i]; c1++){
    ll a = C[i][c1];
    if(a != par){
        dfs2(a,i,best);
    }
}
}

void solve(){
    for(ll c1 = 0; c1 < cents.size(); c1++){
        ll a = cents[c1];
        for(ll c2 = 0; c2 < deg[a]; c2++){
            ll b = C[a][c2];
            if(cent[b] == 0){
                ll best = B[a];
                if(CS[a][c2] == B[a]){
                    best = SB[a];
                }
                dfs2(b,a,best);
            }
        }

    }

}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,g;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;
    for(c1 = 0; c1 < n-1; c1++){
        cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs(0,-1);

    for(c1 = 0; c1 < n; c1++){
        vector<ll> A;
        for(c2 = 0; c2 < deg[c1]; c2++){
            A.push_back(CS[c1][c2]);
        }
        sort(A.begin() , A.end());
        B.push_back(A[deg[c1]-1]);
        if(deg[c1] == 1){SB.push_back(0);}
        else{
        SB.push_back(A[deg[c1]-2]);
        }
        if(B[c1] <= n/2){
            cent[c1] = 1;
            cents.push_back(c1);
            ANS[c1] = 1;

        }
    }

    solve();
    for(c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << " ";
    }

	return 0;
}