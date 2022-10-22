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

using namespace std;
typedef long long ll;

ll big = 1000000007ll;
ll bp = 1168195727ll;
std::vector<ll> A;
std::vector<ll> B;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    int a,b,c;
    int n,m,k,l;
scanf("%d" , &n);
for(c1=0;c1<1100002;c1++)
{

    B.push_back(0);

}
for(c1=0;c1<n;c1++)
{

    scanf("%d" , &a);
    B[a]++;
   // A.push_back(a);

}
//std::sort(A.begin(),A.end());
int ans = 0;
for(c1=0;c1<1100001;c1++)
{

    if(B[c1] % 2 != 0){ans++;}
    B[c1+1] += B[c1]/2;


}
printf("%d\n" , ans);

    return 0;
}