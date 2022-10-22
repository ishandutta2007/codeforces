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
ll n,m,q,h,k,w;
ll T;

vector<ll> A;
vector<ll> A2;

ll indeg[200001] = {0};
ll indeg2[200001] = {0};
ll noncyc[200001] = {0};
ll vis[200001] = {0};

void dfs(ll i){
if(indeg2[i] == 0){
    noncyc[i] = 1;
    indeg2[A[i]]--;
    dfs(A[i]);
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
        cin >> a;
        a--;
        indeg[a]++;
        indeg2[a]++;
        A.push_back(a);
        A2.push_back(a);
    }

    ll root = -1;

    for(c1 = 0; c1 < n; c1++){
        if(noncyc[c1] == 0){dfs(c1);}
        if(A[c1] == c1){root = c1;}
    }

    ll ans = 0;


    for(c1 = 0; c1 < n; c1++){
        if(vis[c1] == 0 && noncyc[c1] == 0 && c1 != root){
            if(root == -1){root = c1;}
            c2 = c1;
            vis[c1] = 1;
            while(A[c2] != c1){
                c2 = A[c2];
                vis[c2] = 1;

            }
            A2[c1] = root;
        }
    }

    for(c1 = 0; c1 < n; c1++){
        if(A[c1] != A2[c1]){ans++;}
    }

    cout << ans << "\n";

    for(c1 = 0; c1 < n; c1++){
        cout << A2[c1]+1 << " ";
    }





	return 0;

}