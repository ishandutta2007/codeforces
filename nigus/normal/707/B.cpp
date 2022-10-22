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

ll K[100001] = {0};
ll deg[100001] = {0};
vector<vector<ll> > C(100000 , vector<ll>());
vector<vector<ll> > CW(100000 , vector<ll>());

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    cin >> n >> m >>k;

    for(c1 = 0; c1 < m; c1++){
        cin >> a >> b >> c;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
        C[a].push_back(b);
        C[b].push_back(a);
        CW[a].push_back(c);
        CW[b].push_back(c);
    }


    ll ans = 133333333337ll;

    if(k == 0){
        cout << "-1\n";
    }
    else{

        for(c1 = 0; c1 < k; c1++){
            cin >> a;
            a--;
            K[a] = 1;
        }

        for(c1 = 0; c1 < n; c1++){
            if(K[c1] == 1){

                for(c2 = 0; c2 < deg[c1]; c2++){
                    a = C[c1][c2];
                    if(K[a] == 0){
                        ans = min(ans , CW[c1][c2]);
                    }
                }

            }
        }

        if(ans == 133333333337){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }

    }


	return 0;
}