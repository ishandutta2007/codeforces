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
ll n,m;
std::vector<ll> A;
std::vector<ll> B;
std::vector<ll> ind;
std::vector<ll> dp;

bool comp(ll i, ll j){
return A[i]<A[j];
}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;
    std::cin >> n;
    for(c1=0;c1<n;c1++){
        std::cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        ind.push_back(c1);
    }
    std::sort(ind.begin(),ind.end(),comp);

    dp.push_back(0);
    for(c1=1;c1<n;c1++){
        a = 0;
        b = c1;
        c = ind[c1];
        x = A[c]-B[c];

        while(a<b-1){
            c2 = (a+b)/2;
            d = ind[c2];
            if(x <= A[d]){
                b = c2;
            }
            else{a = c2;}
        }
        if(x <= A[ind[a]]){b = a;}

        if(b == 0){dp.push_back(c1);}
        else{dp.push_back(c1-b+dp[b-1]);}
        //
        //std::cout << dp[c1] << "\n";
    }

    ll ans = n;
    for(c1=n-1;c1>=0;c1--){

        if(n-c1-1+dp[c1] < ans){ans = n-c1-1+dp[c1];}

    }
std::cout << ans<< "\n";
	return 0;
}