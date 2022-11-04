#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
map<string,vector<int> >mp,ty;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;
    cin>>k>>n;
    for(int i=1;i<=k;i++)
    {
        string str;
        int val;
        cin>>str>>val;
        mp[str].push_back(val);
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++)
        sort(itr->second.begin(),itr->second.end(),greater<int>());
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        string now=itr->first,tmp=now;
        reverse(tmp.begin(),tmp.end());
        if(mp.find(tmp)==mp.end())continue;
        if(now<tmp)
        {
            ty[now].resize(1,0);
            for(int i=0,s=0;i<(int)min(mp[now].size(),mp[tmp].size());i++)
                ty[now][0]=max(ty[now][0],s+=mp[now][i]+mp[tmp][i]);
        }
        else if(now==tmp)
        {
            ty[now].resize(2,0);
            for(int i=0,s=0;i<(int)mp[now].size();i++)
                ty[now][(i&1)^1]=max(ty[now][(i&1)^1],s+=mp[now][i]);
        }
    }
    int now=0;
    for(auto itr=ty.begin();itr!=ty.end();itr++)
        now+=itr->second[0];
    int res=now;
    for(auto itr=ty.begin();itr!=ty.end();itr++)
        if((int)itr->second.size()==2)res=max(res,now-itr->second[0]+itr->second[1]);
    cout<<res<<endl;
    return 0;
}