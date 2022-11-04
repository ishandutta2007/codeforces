#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
struct Procedure
{
    string name;
    vector<string>type;
}p[MAXN];
struct Variable
{
    string name,type;
}v[MAXN];
bool isValid(char x)
{
    return (x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9');
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str,word;
    stringstream ss;
    int n;
    cin>>n;
    getline(cin,str);
    for(int i=1;i<=n;i++)
    {
        getline(cin,str);
        for(int i=0;i<(int)str.size();i++)
            if(!isValid(str[i]))str[i]=' ';
        ss.clear();
        ss.str(str);
        ss>>word>>word;
        p[i].name=word;
        while(ss>>word)
            p[i].type.push_back(word);
    }
    int m;
    cin>>m;
    getline(cin,str);
    for(int i=1;i<=m;i++)
    {
        getline(cin,str);
        ss.clear();
        ss.str(str);
        ss>>word;
        v[i].type=word;
        ss>>word;
        v[i].name=word;
    }
    int k;
    cin>>k;
    getline(cin,str);
    for(int i=1;i<=k;i++)
    {
        getline(cin,str);
        for(int i=0;i<(int)str.size();i++)
            if(!isValid(str[i]))str[i]=' ';
        ss.clear();
        ss.str(str);
        ss>>word;
        p[0].name=word;
        p[0].type.clear();
        while(ss>>word)
            for(int j=1;j<=m;j++)
                if(v[j].name==word)
                    p[0].type.push_back(v[j].type);
        int res=0;
        for(int j=1;j<=n;j++)
        {
            if(p[0].name!=p[j].name)continue;
            if(p[0].type.size()!=p[j].type.size())continue;
            int isok=1;
            for(int k=0;k<(int)p[0].type.size();k++)
                isok&=(p[j].type[k]=="T" || p[j].type[k]==p[0].type[k]);
            res+=isok;
        }
        cout<<res<<endl;
    }
    return 0;
}