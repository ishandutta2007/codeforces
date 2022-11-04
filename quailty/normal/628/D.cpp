#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2005;
const int Mod=1000000007;
char a[MAXN],b[MAXN];
int len,dp[MAXN][MAXN][2];
void add(int &x,int y)
{
    x+=y;
    if(x>=Mod)x-=Mod;
}
int get(char s[],int m,int d)
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<s[0]-'0';i++)
        if(i!=d)dp[1][i%m][0]++;
    if(s[0]-'0'!=d)dp[1][(s[0]-'0')%m][1]=1;
    for(int i=2;i<=len;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<10;k++)
            {
                if(i%2)
                {
                    if(k==d)continue;
                }
                else
                {
                    if(k!=d)continue;
                }
                if(k<s[i-1]-'0')add(dp[i][(j*10+k)%m][0],dp[i-1][j][1]);
                if(k==s[i-1]-'0')add(dp[i][(j*10+k)%m][1],dp[i-1][j][1]);
                add(dp[i][(j*10+k)%m][0],dp[i-1][j][0]);
            }
    return (dp[len][0][0]+dp[len][0][1])%Mod;
}
int main()
{
    int m,d;
    scanf("%d%d",&m,&d);
    scanf("%s%s",a,b);
    len=strlen(a);
    a[len-1]--;
    for(int i=len-1;i>=0;i--)
        while(a[i]<'0')
        {
            a[i]+=10;
            a[i-1]--;
        }
    printf("%d",(get(b,m,d)-get(a,m,d)+Mod)%Mod);
    return 0;
}