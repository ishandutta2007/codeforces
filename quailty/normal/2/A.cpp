#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=1005;
string s[MAXN];
int c[MAXN];
map<string,int>mp;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i]>>c[i];
    for(int i=0;i<n;i++)
        mp[s[i]]+=c[i];
    int res=0;
    for(map<string,int>::iterator itr=mp.begin();itr!=mp.end();itr++)
        res=max(res,itr->second);
    for(map<string,int>::iterator itr=mp.begin();itr!=mp.end();)
    {
        if(itr->second !=res)mp.erase(itr++);
        else (itr++)->second =0;
    }
    for(int i=0;i<n;i++)
        if(mp.find(s[i])!=mp.end())
        {
            mp[s[i]]+=c[i];
            if(mp[s[i]]>=res)
            {
                cout<<s[i]<<endl;
                return 0;
            }
        }
    return 0;
}