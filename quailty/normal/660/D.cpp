#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int x[2005],y[2005];
map<pair<int,int>,int>mp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            mp[make_pair(x[i]+x[j],y[i]+y[j])]++;
    ll res=0;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
        res+=1LL*itr->second*(itr->second -1)/2;
    printf("%I64d",res);
    return 0;
}