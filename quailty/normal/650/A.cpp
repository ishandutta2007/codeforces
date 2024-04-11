#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=200005;
map<ll,ll>mpx,mpy;
map<pair<ll,ll>,ll>mp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        ll x,y;
        scanf("%I64d%I64d",&x,&y);
        mpx[x]++;
        mpy[y]++;
        mp[make_pair(x,y)]++;
    }
    ll res=0;
    for(auto itr=mpx.begin();itr!=mpx.end();itr++)
        res+= itr->second*(itr->second -1)/2;
    for(auto itr=mpy.begin();itr!=mpy.end();itr++)
        res+= itr->second*(itr->second -1)/2;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
        res-= itr->second*(itr->second -1)/2;
    printf("%I64d\n",res);
    return 0;
}