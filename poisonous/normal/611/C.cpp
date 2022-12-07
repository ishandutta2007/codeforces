#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int can[510][510],can2[510][510];
char s[510][510];
int get(int l,int u,int r,int d)
{
    return can[r][d]-can[l-1][d]-can[r][u-1]+can[l-1][u-1];
}
int get2(int l,int u,int r,int d)
{
    return can2[r][d]-can2[l-1][d]-can2[r][u-1]+can2[l-1][u-1];
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='.'&&s[i+1][j]=='.')
                can[i][j]=can[i][j-1]+can[i-1][j]-can[i-1][j-1]+1;
            else
                can[i][j]=can[i][j-1]+can[i-1][j]-can[i-1][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++)
            if(s[i][j]=='.'&&s[i][j+1]=='.')
                can2[i][j]=can2[i][j-1]+can2[i-1][j]-can2[i-1][j-1]+1;
            else
                can2[i][j]=can2[i][j-1]+can2[i-1][j]-can2[i-1][j-1];
    int q;
    cin>>q;
    while(q--)
    {
        int l,u,r,d;
        scanf("%d%d%d%d",&l,&u,&r,&d);
        printf("%d\n",get(l,u,r-1,d)+get2(l,u,r,d-1));
    }
}