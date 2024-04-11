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

std::vector<ll> TQ;
std::vector<ll> D;

std::vector<ll> ANS;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n >> b;
    std::queue<ll> Q;
    for(c1 = 0; c1 < n; c1++){
        std::cin >> a >> c;
        TQ.push_back(a);
        D.push_back(c);
        ANS.push_back(-1);
    }
    TQ.push_back(1000000000000000000ll);
    ll now = 0;
    ll i = 0;
    ll j = 0;
    bool emp = 1;
    while(1==1){
        if(emp == 1){
            now = TQ[i];
            emp = 0;
            j = i;
            if(i == n){break;}
            i++;
        }
        else{
            ll t1 = now + D[j];
            ll t2 = TQ[i];

            if(t1 <= t2){
                ANS[j] = t1;
                if(Q.empty()){
                    emp = 1;
                }
                else{
                    j = Q.front();
                    Q.pop();
                }
                now = t1;
            }
            else{
                if(Q.size() < b){
                Q.push(i);
                }
                i++;
            }
        }
    }

for(c1 = 0; c1 < n; c1++){
    std::cout << ANS[c1] << " ";
}
	return 0;
}