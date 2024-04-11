#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> mp,sg;
int dfs(int mask)
{
    if(!mask)return 0;
    if(sg.find(mask)!=sg.end())return sg[mask];
    int mx=0;
    for(int i=1;i<30;i++)
        if(mask>>i&1)mx=i;
    int vis=0;
    for(int i=1;i<=mx;i++)
    {
        int tmask=((mask>>(i+1))<<1)|(mask&((1<<i)-1));
        vis|=(1<<dfs(tmask));
    }
    int res=0;
    for(int i=30;i>=0;i--)
        if(~vis>>i&1)res=i;
    return sg[mask]=res;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        for(int i=2;i*i<=a;i++)
            if(a%i==0)
            {
                int cnt=0;
                while(a%i==0)
                    a/=i,cnt++;
                mp[i]|=(1<<cnt);
            }
        if(a>1)mp[a]|=(1<<1);
    }
    int sum=0;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
        sum^=dfs(itr->second);
    printf("%s\n",(sum==0 ? "Arpa" : "Mojtaba"));
    return 0;
}