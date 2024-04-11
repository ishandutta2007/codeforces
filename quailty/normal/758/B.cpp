#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int main()
{
    scanf("%s",s);
    int n=strlen(s),res[4]={0},tot[4]={0},cnt[4]={0};
    for(int i=0;i<n;i++)
    {
        tot[i%4]++;
        if(s[i]=='R')res[0]=i%4,cnt[0]++;
        if(s[i]=='B')res[1]=i%4,cnt[1]++;
        if(s[i]=='Y')res[2]=i%4,cnt[2]++;
        if(s[i]=='G')res[3]=i%4,cnt[3]++;
    }
    for(int i=0;i<4;i++)
        printf("%d ",tot[res[i]]-cnt[i]);
    return 0;
}