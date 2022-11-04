#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<pair<int,int>,vector<pair<int,int> > >mp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int r[3];
        for(int j=0;j<3;j++)
            scanf("%d",&r[j]);
        sort(r,r+3);
        for(int j=0;j<3;j++)
        {
            mp[make_pair(r[0],r[1])].push_back(make_pair(-r[2],i));
            mp[make_pair(r[0],r[2])].push_back(make_pair(-r[1],i));
            mp[make_pair(r[1],r[2])].push_back(make_pair(-r[0],i));
        }
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        itr->second.push_back(make_pair(0,0));
        sort(itr->second.begin(),itr->second.end());
        itr->second.erase(unique(itr->second.begin(),itr->second.end()),itr->second.end());
    }
    int res=0;
    pair<int,int>ans=make_pair(0,0);
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        int tmp=min(itr->first.first,itr->first.second);
        tmp=min(tmp,-(itr->second[0].first+itr->second[1].first));
        if(res<tmp)
        {
            res=tmp;
            ans=make_pair(itr->second[0].second,itr->second[1].second);
        }
    }
    //printf("%d\n",res);
    if(!ans.second)printf("1\n%d\n",ans.first);
    else printf("2\n%d %d\n",ans.first,ans.second);
    return 0;
}