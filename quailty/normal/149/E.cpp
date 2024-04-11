#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int nxt[1005];
void getNxt(char s[],int len)
{
    nxt[1]=0;
    for(int i=1;i<len;i++)
    {
        int p=nxt[i];
        while(p && s[p+1]!=s[i+1])p=nxt[p];
        nxt[i+1]=p+(s[p+1]==s[i+1]);
    }
}
void getLoc(char s[],int lens,char t[],int lent,int tim[])
{
    for(int i=(tim[0]=0)+1;i<=lent+1;i++)tim[i]=lens+1;
    for(int i=1,p=0;i<=lens;i++)
    {
        while(p && t[p+1]!=s[i])p=nxt[p];
        p+=(t[p+1]==s[i]);
        tim[p]=min(tim[p],i);
        if(p==lent)p=nxt[p];
    }
}
int pre[1005],suf[1005];
char s[100005],t[1005];
int main()
{
    scanf("%s",s+1);
    int lens=strlen(s+1),m,res=0;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%s",t+1);
        int lent=strlen(t+1);
        getNxt(t,lent);
        getLoc(s,lens,t,lent,pre);
        reverse(s+1,s+lens+1);
        reverse(t+1,t+lent+1);
        getNxt(t,lent);
        getLoc(s,lens,t,lent,suf);
        reverse(s+1,s+lens+1);
        reverse(suf,suf+lent+2);
        for(int i=0;i<=lent+1;i++)
            suf[i]=lens+1-suf[i];
        int isok=0;
        for(int i=1;i<lent;i++)
            isok|=(pre[i]<suf[i+1]);
        res+=isok;
    }
    printf("%d\n",res);
    return 0;
}