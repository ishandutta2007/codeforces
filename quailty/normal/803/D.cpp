#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
char s[MAXN];
int c[MAXN];
int main()
{
    int k;
    scanf("%d",&k);
    gets(s);
    gets(s);
    int now=0,cnt=0;
    for(int i=0;s[i];i++)
    {
        now++;
        if(s[i]=='-' || s[i]==' ')
            c[cnt++]=now,now=0;
    }
    c[cnt++]=now;
    int l=1,r=MAXN;
    while(l<r)
    {
        int m=(l+r)/2,cur=0,tot=1;
        for(int i=0;i<cnt;i++)
        {
            if(c[i]>m)tot=MAXN;
            if(c[i]+cur>m)
            {
                cur=c[i];
                tot++;
            }
            else cur+=c[i];
        }
        if(tot<=k)r=m;
        else l=m+1;
    }
    return 0*printf("%d",l);
}