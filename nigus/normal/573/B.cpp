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
std::vector<ll> A;
std::vector<ll> S1;
std::vector<ll> S2;
std::vector<ll> S;
int n,a;

int main()
{

    ll m,x,y,z,b,c;
    ll c1,c2,c3,c4,c5,c6;

    scanf("%d",&n);
    int ans;
    bool fail =0;
    for(c1=0;c1<n;c1++)
    {
        scanf("%d",&a);
        A.push_back(a);

    }

    S1.push_back(1);
    for(c1=1;c1<n;c1++)
    {

        m = min(S1[c1-1]+1 , A[c1]);
        S1.push_back(m);


    }
    S2.push_back(1);
    for(c1=1;c1<n;c1++)
    {
        c2 = n-1-c1;
        m = min(S2[c1-1]+1 , A[c2]);
        S2.push_back(m);


    }
    ans=0;
    for(c1=0;c1<n;c1++)
    {
        c2 = n-1-c1;
        m = min(S1[c1] , S2[c2]);
        if(m>ans){ans=m;}


    }
printf("%d\n" , ans);

	return 0;
}