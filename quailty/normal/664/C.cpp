#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int,string>mp;
map<string,int>usd;
void build()
{
    string str;
    for(int i=1989;i<10000;i++)
    {
        str.clear();
        int t=i;
        while(t)
        {
            str+=t%10+'0';
            t/=10;
        }
        reverse(str.begin(),str.end());
        for(int j=(int)str.size()-1;j>=0;j--)
        {
            string tmp=str.substr(j);
            if(usd.find(tmp)==usd.end())
            {
                mp[i]=tmp;
                usd[tmp]=i;
                break;
            }
        }
    }
}
int main()
{
    build();
    int n;
    string str;
    cin>>n;
    while(n--)
    {
        cin>>str;
        int loc=0;
        for(int i=0;i<(int)str.size();i++)
            if(str[i]=='\'')loc=i;
        str=str.substr(loc+1);
        if(usd.find(str)!=usd.end())
            cout<<usd[str]<<endl;
        else
        {
            string tmp;
            for(int i=0;i<(int)str.size()-4;i++)tmp+='1';
            tmp+="3098";
            cout<<(str<=tmp ? "1" : "")<<str<<endl;
        }
    }
    return 0;
}