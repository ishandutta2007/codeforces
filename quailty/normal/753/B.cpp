#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
pair<int,int>query(string s)
{
    cout<<s<<endl;
    int b,c;
    scanf("%d%d",&b,&c);
    return make_pair(b,c);
}
int usd[10];
void build(int dep,string now,vector<string>&v)
{
    if(dep==4)
    {
        v.push_back(now);
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(usd[i])continue;
        usd[i]=1;
        build(dep+1,now+(char)('0'+i),v);
        usd[i]=0;
    }
}
pair<int,int>check(string a,string b)
{
    pair<int,int>res;
    for(int i=0;i<4;i++)
        res.first+=(a[i]==b[i]);
    for(int i=0;i<4;i++)
        usd[a[i]-'0']=1;
    for(int i=0;i<4;i++)
        res.second+=usd[b[i]-'0'];
    for(int i=0;i<4;i++)
        usd[a[i]-'0']=0;
    res.second-=res.first;
    return res;
}
vector<string>rebuild(vector<string>v,pair<int,int>res)
{
    vector<string>tmp;
    for(int i=1;i<(int)v.size();i++)
        if(check(v[i],v[0])==res)tmp.push_back(v[i]);
    return tmp;
}
int main()
{
    srand(time(NULL));
    vector<string>v;
    build(0,"",v);
    while(1)
    {
        random_shuffle(v.begin(),v.end());
        pair<int,int>res=query(v[0]);
        if(res.first==4)break;
        v=rebuild(v,res);
    }
    return 0;
}