#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[55][55],t[55][55];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    int mx=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mx=max(mx,s[i][j]-'0');
    if(mx<=3)return 0*printf("No");
    int x[2]={51,0},y[2]={51,0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[i][j]=='0'+mx)
            {
                x[0]=min(x[0],i);
                x[1]=max(x[1],i);
                y[0]=min(y[0],j);
                y[1]=max(y[1],j);
            }
    x[0]--,y[0]--;
    memset(t,'0',sizeof(t));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int p=0;p<2;p++)
                for(int q=0;q<2;q++)
                {
                    int tx=i-p,ty=j-q;
                    if(tx>=x[0] && tx<=x[1] && ty>=y[0] && ty<=y[1])
                        t[i][j]++;
                }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[i][j]!=t[i][j])
                return 0*printf("No");
    return 0*printf("Yes");
}