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
//ll T;


int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n >> k >> q;

    std::vector<ll> T;
    std::priority_queue<ll> PQ;
    std::vector<ll> mark;
    std::map<ll,ll> M;

    for(c1 = 0; c1 < n; c1++){
        std::cin >> a;
        T.push_back(a);
        M[a] = c1;
        mark.push_back(0);
    }

    for(c1 = 0; c1 < q; c1++){

        std::cin >> a >> b;
        b--;
        if(a == 2){
            if(mark[b] == 1){std::cout << "YES\n";}
            else{std::cout << "NO\n";}
        }
        else{

            if(PQ.empty()){
                PQ.push(-T[b]);
                mark[b] = 1;
            }
            else{

                if(-PQ.top() > -T[b]){
                    PQ.push(-T[b]);
                    mark[b] = 1;
                    if(PQ.size() > k){
                        c2 = -PQ.top();
                        PQ.pop();
                        mark[M[c2]] = 0;
                    }
                }

            }

        }

    }

	return 0;
}