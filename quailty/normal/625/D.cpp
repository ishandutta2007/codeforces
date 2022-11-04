#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
char ts[100005],t[100005];
int s[100005];
bool solve(int len)
{
    memset(t,0,sizeof(t));
    bool isok=1;
    for(int i=0;i<len/2;i++)
    {
        while(s[len-1-i]<0)
        {
            s[len-i-1]+=10;
            s[len-i-2]--;
        }
        int tt=s[i]/10*10+s[len-i-1]%10;
        if(tt>18)tt-=10;
        t[i]=tt-tt/2+'0';
        t[len-i-1]=tt/2+'0';
        s[i]-=tt;
        s[len-i-1]-=tt;
        while(s[len-1-i]<0)
        {
            s[len-i-1]+=10;
            s[len-i-2]--;
        }
        if(s[i]>1 || s[i]<0)
        {
            isok=0;
            break;
        }
        s[i+1]+=s[i]*10;
        s[i]=0;
    }
    if(len%2==1)
    {
        if(s[len/2]%2==0 && s[len/2]<=18 && s[len/2]>=0)
        {
            t[len/2]=s[len/2]/2+'0';
            s[len/2]=0;
        }
    }
    for(int i=0;i<len;i++)
        if(s[i]!=0)isok=0;
    if(isok && t[0]!='0')printf("%s",t);
    return isok && t[0]!='0';
}
int main()
{
    scanf("%s",ts);
    int len=strlen(ts);
    for(int i=0;i<len;i++)
        s[i]=ts[i]-'0';
    if(!solve(len))
    {
        for(int i=0;i<len;i++)
            s[i]=ts[i]-'0';
        if(s[0]==1 && len>1)
        {
            s[1]+=10;
            for(int i=0;i<len;i++)
                s[i]=s[i+1];
            if(!solve(len-1))printf("0");
        }
        else printf("0");
    }
    return 0;
}