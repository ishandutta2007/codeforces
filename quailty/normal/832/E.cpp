#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=505;
const int Mod=1000000007;
char s[MAXN];
int a[MAXN][MAXN],b[MAXN];
int inv[5]={0,1,3,2,4},md5[25];
int main()
{
    for(int i=0;i<25;i++)
        md5[i]=i%5;
    int n,m;
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m;j++)
            b[j]=s[j]-'a';
        for(int k=0;k<cnt;k++)
        {
            for(int j=0;j<m;j++)if(a[k][j])
            {
                int t=md5[b[j]*inv[a[k][j]]];
                for(int l=0;l<m;l++)
                    b[l]=md5[b[l]-md5[t*a[k][l]]+5];
                break;
            }
        }
        bool flag=0;
        for(int j=0;j<m;j++)
            flag|=(b[j]>0);
        if(flag)
        {
            for(int j=0;j<m;j++)
                a[cnt][j]=b[j];
            cnt++;
        }
    }
    int res=1;
    for(int i=0;i<n-cnt;i++)
        res=5LL*res%Mod;
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m;j++)
            b[j]=s[j]-'a';
        for(int k=0;k<cnt;k++)
        {
            for(int j=0;j<m;j++)if(a[k][j])
            {
                int t=md5[b[j]*inv[a[k][j]]];
                for(int l=0;l<m;l++)
                    b[l]=md5[b[l]-md5[t*a[k][l]]+5];
                break;
            }
        }
        bool flag=0;
        for(int j=0;j<m;j++)
            flag|=(b[j]>0);
        printf("%d\n",(flag ? 0 : res));
    }
    return 0;
}