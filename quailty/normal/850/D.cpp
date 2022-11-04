#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[0061],c[0061+61],id[0061+61];
bool dp[0061][0061+61][0061*0061];
bool pr[0061][0061+61][0061*0061];
char str[0061+61][0061+61];
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    dp[0][0][0]=1;
    for(int i=1;i<=m;i++)
        for(int j=0;j<=61;j++)
            for(int k=(j+1)*j/2-a[i];k+a[i]<0061*0061;k++)
            {
                int tj=j+1,tk=k+a[i];
                if(tk<tj*(tj-1)/2)continue;
                if(dp[i-1][j][k])
                    dp[i][tj][tk]=1,pr[i][tj][tk]=1;
                if(dp[i][j][k])
                    dp[i][tj][tk]=1,pr[i][tj][tk]=0;
            }
    int res=0061+61;
    for(int j=61;j>=0;j--)
        if(dp[m][j][j*(j-1)/2])
            res=j;
    if(res>61)return 0*printf("=(\n");
    printf("%d\n",res);
    int ti=m,tj=res,tk=tj*(tj-1)/2,tot=0;
    while(ti)
    {
        bool t=pr[ti][tj][tk];
        c[tot++]=a[ti];
        tk-=a[ti],ti-=t,tj-=1;
    }
    for(int i=0;i<res;i++)
        id[i]=i;
    for(int _=0;_<res;_++)
    {
        sort(id+_,id+res,[](int a,int b){return c[a]>c[b];});
        str[id[_]][id[_]]='0';
        for(int i=res-1;i>_;i--)
        {
            int w=(c[id[_]]>0);
            str[id[_]][id[i]]=w+'0',str[id[i]][id[_]]=1-w+'0';
            c[id[_]]-=w,c[id[i]]-=1-w;
        }
    }
    for(int i=0;i<res;i++)
        printf("%s\n",str[i]);
    return 0;
}