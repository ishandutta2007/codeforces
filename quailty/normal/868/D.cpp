#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=105;
const int MAXK=18;
const int SIZE=(1<<(MAXK+1))+5;
int st[MAXN];
string str[MAXN];
struct data
{
    int len;
    string pre,suf;
    bitset<SIZE> vis;
}s[MAXN<<1];
int main()
{
    st[1]=0;
    for(int i=2;i<=MAXK;i++)
        st[i]=st[i-1]+(1<<(i-1));
    int n;
    cin>>n;
    for(int _=0;_<n;_++)
    {
        string str;
        cin>>str;
        s[_].len=(int)str.size();
        s[_].vis.reset();
        for(int i=0;i<(int)str.size();i++)
        {
            int mask=0;
            for(int j=i;j<i+MAXK && j<(int)str.size();j++)
            {
                mask=mask<<1|(str[j]-'0');
                s[_].vis.set(st[j-i+1]+mask);
            }
        }
        if(s[_].len>MAXK)
        {
            s[_].pre=str.substr(0,MAXK);
            s[_].suf=str.substr(s[_].len-MAXK);
            s[_].len=MAXK;
        }
        else s[_].pre=s[_].suf=str;
    }
    int m;
    cin>>m;
    for(int _=n;_<n+m;_++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        string str=s[a].suf+s[b].pre;
        s[_].len=s[a].len+s[b].len;
        s[_].vis=s[a].vis|s[b].vis;
        for(int i=0;i<(int)str.size();i++)
        {
            int mask=0;
            for(int j=i;j<i+MAXK && j<(int)str.size();j++)
            {
                mask=mask<<1|(str[j]-'0');
                s[_].vis.set(st[j-i+1]+mask);
            }
        }
        if(s[_].len>MAXK)
        {
            if(s[a].len<MAXK)s[_].pre=str.substr(0,MAXK);
            else s[_].pre=s[a].pre;
            if(s[b].len<MAXK)s[_].suf=str.substr((int)str.size()-MAXK);
            else s[_].suf=s[b].suf;
            s[_].len=MAXK;
        }
        else s[_].pre=s[_].suf=str;
        int res=0;
        for(int i=1;i<=MAXK;i++)
        {
            bool flag=1;
            for(int j=st[i];j<st[i]+(1<<i);j++)
                flag&=s[_].vis[j];
            if(flag)res=i;
        }
        cout<<res<<endl;
    }
    return 0;
}