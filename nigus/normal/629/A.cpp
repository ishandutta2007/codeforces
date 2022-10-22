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
ll n,m,k,q;
ll T;

std::vector<ll> A;
std::vector<ll> B;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    std::cin >> n;
    c3=0;
    c4=0;
    for(c1=0;c1<n;c1++){B.push_back(0);A.push_back(0);}
    for(c1=0;c1<n;c1++){
        std::cin >> s;
        for(c2=0;c2<n;c2++){
            if(s[c2] == 'C'){A[c1]++;B[c2]++;}
        }
    }


    ll ans = 0;
    for(c1=0;c1<n;c1++){
        ans += A[c1]*(A[c1]-1)/2;
        ans += B[c1]*(B[c1]-1)/2;
    }
    std::cout << ans << "\n";

	return 0;
}