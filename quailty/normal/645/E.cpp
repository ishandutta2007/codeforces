#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1000005;
const int MAXM=1000005;
const int MAXK=26+5;
const int Mod=1000000007;
int dp[MAXN+MAXM],las[MAXK];
char s[MAXM];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    int m=strlen(s+1);
    for(int i=1;i<=m;i++)
    {
        if(!las[s[i]-'a'])dp[i]=(2*dp[i-1]+1)%Mod;
        else dp[i]=(2*dp[i-1]%Mod-dp[las[s[i]-'a']-1]+Mod)%Mod;
        las[s[i]-'a']=i;
    }
    for(int i=m+1;i<=m+n;i++)
    {
        int loc=0;
        for(int j=0;j<k;j++)
        {
            if(!las[j])
            {
                loc=j;
                break;
            }
            else if(las[j]<las[loc])
                loc=j;
        }
        int buf;
        if(!las[loc])buf=1;
        else buf=-dp[las[loc]-1];
        dp[i]=(2*dp[i-1]%Mod+buf+Mod)%Mod;
        las[loc]=i;
    }
    printf("%d\n",(dp[m+n]+1)%Mod);
    return 0;
}