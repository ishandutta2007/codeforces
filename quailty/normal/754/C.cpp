#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=105;
map<string,int>mp;
string v[MAXN];
void init()
{
    mp.clear();
}
int getId(string s)
{
    if(!mp[s])v[mp[s]=(int)mp.size()]=s;
    return mp[s];
}
string text[MAXN];
int a[MAXN],usd[MAXN][MAXN],dp[MAXN][MAXN];
bool isAlpha(char x)
{
    return ((x>='a' && x<='z') || (x>='A' && x<='Z'));
}
bool isDigit(char x)
{
    return (x>='0' && x<='9');
}
int main()
{
    stringstream ss;
    int T;
    cin>>T;
    while(T--)
    {
        init();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>text[0],getId(text[0]);
        int m;
        cin>>m;
        getline(cin,text[0]);
        for(int i=1;i<=m;i++)
        {
            getline(cin,text[i]);
            string tmp=text[i];
            a[i]=(tmp[0]!='?');
            for(int i=0;i<(int)tmp.size();i++)
                if(!isAlpha(tmp[i]) && !isDigit(tmp[i]))tmp[i]=' ';
            ss.clear();
            ss.str(tmp);
            if(a[i])
            {
                ss>>text[0];
                a[i]=getId(text[0]);
            }
            for(int j=1;j<=n;j++)
                usd[i][j]=0;
            while(ss>>text[0])
                if(mp.find(text[0])!=mp.end())
                    usd[i][mp[text[0]]]=1;
        }
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=0;
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
        {
            int sum=0;
            for(int j=0;j<=n;j++)
                sum+=dp[i-1][j];
            if(a[i])dp[i][a[i]]|=(sum>dp[i-1][a[i]]);
            else for(int j=1;j<=n;j++)
                dp[i][j]|=(!usd[i][j] && sum>dp[i-1][j]);
        }
        int t=0;
        for(int j=1;j<=n;j++)
            if(dp[m][j])t=j;
        if(!t)cout<<"Impossible"<<endl;
        else
        {
            for(int i=m;i>=1;i--)
                for(int j=0;j<=n;j++)
                    if(j!=t && dp[i-1][j])
                    {
                        if(!a[i])a[i]=-t;
                        t=j;
                        break;
                    }
            for(int i=1;i<=m;i++)
            {
                if(a[i]>0)cout<<text[i]<<endl;
                else cout<<v[abs(a[i])]+text[i].substr(1)<<endl;
            }
        }
    }
    return 0;
}