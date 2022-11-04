#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1005],t[1005];
int cnts[10],cntt[10];
int main()
{
    int n;
    scanf("%d%s%s",&n,s,t);
    for(int i=0;i<n;i++)
        cnts[s[i]-'0']++,cntt[t[i]-'0']++;
    int res=0;
    for(int i=9;i>=0;i--)
    {
        int tmp=min(cntt[i],cnts[i]);
        res+=tmp;
        if(i>0)cntt[i-1]+=cntt[i]-tmp;
    }
    printf("%d\n",n-res);
    res=0;
    for(int i=0;i<10;i++)
        cnts[i]=cntt[i]=0;
    for(int i=0;i<n;i++)
        cnts[s[i]-'0']++,cntt[t[i]-'0']++;
    for(int i=9;i>0;i--)
    {
        int tmp=min(cntt[i],cnts[i-1]);
        res+=tmp;
        cntt[i-1]+=cntt[i]-tmp;
    }
    printf("%d\n",res);
    return 0;
}