#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5000005;
char Ma[MAXN<<1];
int Mp[MAXN<<1];
void Manacher(char s[],int len)
{
    int l=0;
    Ma[l++]='$';
    Ma[l++]='#';
    for(int i=0;i<len;i++)
    {
        Ma[l++]=s[i];
        Ma[l++]='#';
    }
    Ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;i++)
    {
        Mp[i]=(mx>i ? min(Mp[2*id-i],mx-i) : 1);
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
}
char s[MAXN];
int dp[MAXN];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    Manacher(s+1,n);
    int res=0;
    for(int i=1;i<=n;i++)
        res+=dp[i]=(Mp[i+1]>=i ? dp[i/2]+1 : 0);
    printf("%d\n",res);
    return 0;
}