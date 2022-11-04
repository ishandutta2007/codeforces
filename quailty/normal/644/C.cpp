#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int MAXN=100005;
map<string,int>mph,mpp;
string sh[MAXN];
vector<int>v[MAXN];
map<vector<int>,vector<int> >mp;
int get_hid(string &s)
{
    if(!mph[s])
    {
        mph[s]=(int)mph.size();
        sh[mph[s]]=s;
    }
    return mph[s];
}
int get_pid(string &s)
{
    if(!mpp[s])mpp[s]=(int)mpp.size();
    return mpp[s];
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        int loc=-1;
        for(int i=0;i<(int)str.size();i++)
            if(str[i]=='/')
            {
                if(i+1<(int)str.size() && str[i+1]=='/')i++;
                else
                {
                    loc=i;
                    break;
                }
            }
        string host,path;
        if(loc<0)host=str;
        else host=str.substr(0,loc);
        get_hid(host);
        if(loc>=0)path=str.substr(loc);
        v[get_hid(host)].push_back(get_pid(path));
    }
    for(int i=1;i<=(int)mph.size();i++)
    {
        sort(v[i].begin(),v[i].end());
        v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
    }
    for(int i=1;i<=(int)mph.size();i++)
        mp[v[i]].push_back(i);
    for(auto itr=mp.begin();itr!=mp.end();)
    {
        if((int)itr->second.size()>1)itr++;
        else mp.erase(itr++);
    }
    cout<<(int)mp.size()<<endl;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        for(int i=0;i<(int)itr->second.size();i++)
            cout<<sh[itr->second[i]]<<" ";
        cout<<endl;
    }
    return 0;
}