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
std::vector<ll> ind;
std::vector<char> gen;
std::vector<ll> minu;
bool comp(ll i,ll j){
    if(A[i] == A[j]){return minu[i] < minu[j];}
return A[i]<A[j];
}
int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n;
    char ch;
    for(c1=0;c1<n;c1++){
        std::cin >> ch >> a >> b;
        A.push_back(a);
        ind.push_back(2*c1);
        gen.push_back(ch);
        minu.push_back(1);
        A.push_back(b+1);
        ind.push_back(2*c1+1);
        gen.push_back(ch);
        minu.push_back(-1);
    }
std::sort(ind.begin(),ind.end(),comp);
ll ans = 0;
ll M,F;
M=0;
F=0;
for(c1=0;c1<2*n;c1++){
    a = ind[c1];
//std::cout << gen[a] << "   " << A[a] << "\n";
    if(gen[a] == 'F'){F+=minu[a];}
    if(gen[a] == 'M'){M+=minu[a];}
    if(2 * min(M,F) > ans){ans = 2 * min(M,F);}
}
std::cout << ans << "\n";
	return 0;
}