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
int main()
{

    ll m,x,y,z,c;
    ll c1,c2,c3,c4,c5,c6;
    ll n;
    ll a,b,d,e,f;
    std::cin >> n >> m;
    ll sq1=0;
    ll sq2=0;
    for(c1=0;c1<m;c1++){
        A.push_back(0);

    }
    for(c1=0;c1<n;c1++)
    {

        std::cin >> a;
        a--;
        A[a]++;

    }

    for(c1=0;c1<m;c1++)
    {

        a = A[c1];
        sq1 += a;
        sq2 += a*a;
    }
    sq1 *=sq1;

    ll ans = sq1-sq2;
    ans /=2;
    std::cout << ans << "\n";
	return 0;
}