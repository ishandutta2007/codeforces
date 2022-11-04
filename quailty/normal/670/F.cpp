#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
const int u[7]={0,9,99,999,9999,99999,999999};
const int d[7]={0,1,10,100,1000,10000,100000};
char s[MAXN],t[MAXN];
int cnt[10];
char r1[MAXN],r2[MAXN],res[MAXN];
int main()
{
    scanf("%s%s",s,t);
    if(strcmp(s,"01")==0 || strcmp(s,"10")==0)
        return 0*printf("0");
    int n=strlen(s),m=strlen(t);
    for(int i=min(6,n-1);i>=1;i--)
    {
        memset(cnt,0,sizeof(cnt));
        int len=n-i;
        if(len<d[i] || len>u[i])continue;
        for(int i=0;i<n;i++)
            cnt[s[i]-'0']++;
        int r=len;
        while(r)
        {
            cnt[r%10]--;
            r/=10;
        }
        for(int i=0;i<m;i++)
            cnt[t[i]-'0']--;
        bool isok=1;
        for(int i=0;i<10;i++)
            if(cnt[i]<0)isok=0;
        if(!isok)continue;
        bool flag=0;
        if(t[0]!='0')
        {
            flag=1;
            for(int i=0;i<m;i++)r1[i]=t[i];
            int now=m;
            for(int i=0;i<10;i++)
                for(int j=0;j<cnt[i];j++)
                    r1[now++]=i+'0';
        }
        int isup=0;
        for(int i=0;i<m && !isup;i++)
        {
            if(t[i]>t[0])isup=1;
            if(t[i]<t[0])break;
        }
        int now=0;
        bool head=0;
        for(int i=1;i<10;i++)
            if(cnt[i])
            {
                r2[now++]=i+'0';
                cnt[i]--;
                head=1;
                break;
            }
        if(head)
        {
            for(int i=0;i<t[0]-'0'+isup;i++)
                for(int j=0;j<cnt[i];j++)
                    r2[now++]=i+'0';
            for(int i=0;i<m;i++)r2[now++]=t[i];
            for(int i=t[0]-'0'+isup;i<10;i++)
                for(int j=0;j<cnt[i];j++)
                    r2[now++]=i+'0';
        }
        if(flag && head)
        {
            if(strcmp(r1,r2)<0)printf("%s",r1);
            else printf("%s",r2);
        }
        else if(head)printf("%s",r2);
        else if(flag)printf("%s",r1);
        else continue;
        break;
    }
    return 0;
}