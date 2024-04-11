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

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k,q,d;
ll T;

std::vector<ll> TR;
std::vector<ll> TC;

std::vector<ll> CR;
std::vector<ll> CC;


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n >> m >> k;

    for(c1 = 0; c1 < n; c1++){
        TR.push_back(0);
        CR.push_back(0);
    }

    for(c1 = 0; c1 < m; c1++){
        TC.push_back(0);
        CC.push_back(0);
    }

    for(c1 = 1; c1 < k+1; c1++){
        std::cin >> a >> b >> c;
        b--;
        if(a == 1){
            TR[b] = c1;
            CR[b] = c;
        }
        else{
            TC[b] = c1;
            CC[b] = c;
        }
    }

    for(c1 = 0; c1<n;c1++){
        for(c2 = 0; c2 < m;c2++){
            if(TR[c1] > TC[c2]){
                std::cout << CR[c1] << " ";
            }
            else{
                std::cout << CC[c2] << " ";
            }
        }
        std::cout << "\n";
    }


	return 0;
}