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

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,d,h,k,w,x;
//ll T;

vector<ll> A;

vector<vector<ll> > C(100001 , vector<ll>());
vector<vector<ll> > CW(100001 , vector<ll>());
vector<ll> deg;

ll mark[100001] = {0};




void dfs(ll i, ll bad){

//cout << i+1 << " " << bad << "\n";

if(bad > A[i]){mark[i] = 1;}
for(ll c1 = 0; c1 < deg[i]; c1++){

    ll a = C[i][c1];
    ll b = CW[i][c1];



    if(mark[i] == 1){mark[a] = 1;}
    ll bad2 = max(bad + b,0ll);
    dfs(a , bad2);
}
return;
}



int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;

    for(c1 = 0; c1 < n; c1++){
        deg.push_back(0);
        cin >> a;
        A.push_back(a);
    }

    for(c1 = 0; c1 < n-1; c1++){

        cin >> a >> b;
        a--;
        deg[a]++;
        C[a].push_back(c1+1);
        CW[a].push_back(b);
    }

    dfs(0,0);

    ll ans = 0;

    for(c1 = 0; c1 < n; c1++){
        if(mark[c1] == 1){ans++;}

    }

cout << ans << "\n";

	return 0;

}