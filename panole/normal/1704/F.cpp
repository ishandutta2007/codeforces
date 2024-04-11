#include<bits/stdc++.h>
using namespace std;

int sg[500010],T,n,nw,cntr,cntb;
char s[500010];

int main()
{
    sg[0]=0;
    for (int i=1; i<=500; i++)
    {
        bool bo[100];memset(bo,0,sizeof(bo));
        for (int j=1; j<=i; j++) bo[sg[max(j-2,0)]^sg[max(i-1-j,0)]]=1;
        sg[i]=0;
        while (bo[sg[i]]) sg[i]++;
    }
    for (int i=100; i<=500; i++) assert(sg[i-34]==sg[i]);
    for (int i=501; i<=500000; i++) sg[i]=sg[i-34];
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n),scanf("%s",s+1),cntr=cntb=0;
        for (int i=1; i<=n; i++) if (s[i]=='R') cntr++; else cntb++;
        if (cntr!=cntb) {puts(cntr>cntb?"Alice":"Bob"); continue;}
        nw=0;
        for (int i=1; i<n; i++) if (s[i]!=s[i+1])
        {
            int j=i;
            while (j<n-1&&s[j+1]!=s[j+2]) j++;
            nw^=sg[j-i+1],i=j;
        } 
        puts(nw?"Alice":"Bob");
    }
    return 0;
}