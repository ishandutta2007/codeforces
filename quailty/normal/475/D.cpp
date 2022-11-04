#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<int,ll> mp[2],res;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        mp[0]=mp[1],mp[1].clear();
        mp[1][a]++,res[a]++;
        for(auto itr=mp[0].begin();itr!=mp[0].end();itr++)
        {
            int g=__gcd(itr->first,a);
            mp[1][g]+=itr->second;
            res[g]+=itr->second;
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%lld\n",res[x]);
    }
    return 0;
}