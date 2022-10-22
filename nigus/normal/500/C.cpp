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
ll big = 1000000007ll;
ll n,m,k;



std::vector<ll> W;
std::vector<ll> A;
std::vector<ll> mark;
std::vector<ll> sumw;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;

    std::cin >> n >> m;

    for(c1=0;c1<n;c1++){
            mark.push_back(0);
        std::cin >> a;
        W.push_back(a);
        sumw.push_back(0);
    }

    for(c1=0;c1<m;c1++){
        std::cin >> a;
        a--;
        A.push_back(a);
    }
    ll ans=0;
    ll sw =0;
    for(c1=0;c1<m;c1++){

        sw=0;
        for(c2=0;c2<n;c2++){
            mark[c2] = 0;
        }
        c2 = c1-1;
        while(c2 >= 0 && A[c2] != A[c1]){

            if(mark[A[c2]] != 1){
                mark[A[c2]]=1;
                sw += W[A[c2]];

            }

            c2--;
        }
        ans += sw;


    }
    std::cout << ans << "\n";





	return 0;
}