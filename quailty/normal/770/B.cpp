#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    auto cmp=[](const string &a,const string &b)
    {
        int res[2]={0,0};
        for(int i=0;i<(int)a.size();i++)
            res[0]+=a[i];
        for(int i=0;i<(int)b.size();i++)
            res[1]+=b[i];
        if(res[0]==res[1])return a<b;
        else return res[0]<res[1];
    };
    string str;
    cin>>str;
    string res=str;
    for(int i=0;i<(int)str.size();i++)
    {
        if(str[i]=='0')continue;
        string tmp=str.substr(0,i);
        tmp+=str[i]-1;
        while(tmp.size()<str.size())tmp+='9';
        res=max(res,tmp,cmp);
    }
    if(res[0]=='0')res=res.substr(1);
    cout<<res<<endl;
    return 0;
}